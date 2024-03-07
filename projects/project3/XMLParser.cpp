// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
	@file XMLParser.cpp */

#include <string>
#include <assert.h>
#include <vector>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	tokenizedInputVector.clear();
	elementNameBag = new Bag<std::string>;
	stackStack = new Stack<std::string>();
} // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	clear();
	delete elementNameBag;
	delete stackStack;
} // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{

	string invalid = "!#\"$%&'()*+,/;<=>?@[\\]^`{|}~";

	int j = 0;
	int i = 0;

	vector<string> stringInsideTriangle;
	vector<bool> stringInsideTriangleIsContent;
	string tempString = "";

	for (int i = 1; i < inputString.size() - 1; i++)
	{
		if (inputString[i - 1] == '<')
		{

			tempString = "";
			while (inputString[i] != '>' && i<inputString.length())
			{
				if (inputString[i] == '<')
				{
					return false;
				}

				tempString = tempString + inputString[i];
				i++;
			}
			if (tempString.length() != 0)
			{
				stringInsideTriangle.push_back(tempString);
				stringInsideTriangleIsContent.push_back(false); // pushing zero becuase it is not content
				i++;
			}
		}
		else
		{
			i--;
			tempString = "";
			while (inputString[i] != '<' && i < inputString.length())
			{
				if (isspace(inputString[i]))
				{
					tempString = "";
					i++;
					break;
				}
				else
				{
					tempString = tempString + inputString[i];
					i++;
				}
			}
			if (tempString.length() != 0)
			{
				stringInsideTriangle.push_back(tempString);
				stringInsideTriangleIsContent.push_back(true); // pushing zero becuase it is  content
			}
		}
	}

	vector<int> count(stringInsideTriangle.size(), 0);

	for (int k = 0; k < stringInsideTriangle.size(); k++)
		for (int j = 0; j < stringInsideTriangle[k].length(); j++)
		{
			if (stringInsideTriangle[k][j] == '/')
			{
				count[k]++;
			}
			if (count[k] > 1)
			{
				return false;
			}
		}

	// at this point we have what is inside the <> in the string Vector string Inside Triangle
	// we need to get rid of all of the unecceseary characters so not the name and /

	vector<string> nameVector;

	for (i = 0; i < stringInsideTriangle.size(); i++)
	{
		int j = 0;
		string tempString = "";

		while ((!isspace(stringInsideTriangle[i][j]) && stringInsideTriangle[i][j] != '-' && stringInsideTriangle[i][j] != '>') && j < stringInsideTriangle[i].length())
		{
			if (stringInsideTriangle[i][j] == '/' || stringInsideTriangle[i][j] == '?')
			{
				j++;
			}

			else
			{
				tempString = tempString + stringInsideTriangle[i][j];
				j++;
			}
		}

		TokenStruct temp;
		temp.tokenString = tempString;

		string testingValid;

		tokenizedInputVector.push_back(temp);
	}

	// At this point we have the name, content, and xml but we do not have the type, so we need to etract the type from the stringInsideTrangleVector

	for (int i = 0; i < stringInsideTriangle.size(); i++)
	{
		if (stringInsideTriangle[i][0] == '/')
		{
			tokenizedInputVector[i].tokenType = END_TAG;
		}
		else if (stringInsideTriangle[i][0] == '?' && stringInsideTriangle[i][stringInsideTriangle[i].length() - 1] == '?')
		{
			tokenizedInputVector[i].tokenType = DECLARATION;
			tokenizedInputVector[i].tokenString = stringInsideTriangle[i].substr(1, stringInsideTriangle[i].length() - 2);
		}
		else if (stringInsideTriangle[i][stringInsideTriangle[i].length() - 1] == '/')
		{
			tokenizedInputVector[i].tokenType = EMPTY_TAG;
		}
		else if (stringInsideTriangleIsContent[i] == true)
		{
			tokenizedInputVector[i].tokenType = CONTENT;
		}
		else if (stringInsideTriangleIsContent[i] == false)
		{
			tokenizedInputVector[i].tokenType = START_TAG;
			elementNameBag->add(tokenizedInputVector[i].tokenString);
		}
	}

	for (int k = 0; k < tokenizedInputVector.size(); k++)
	{
		if (tokenizedInputVector[k].tokenType != DECLARATION)
		{
			for (int j = 0; j < tokenizedInputVector[k].tokenString.length(); j++)
			{
				for (int i = 0; i < invalid.length(); i++)
				{
					if (tokenizedInputVector[k].tokenString[j] == invalid[i])
					{
						clear();
						return false;
					}
					if (isspace(tokenizedInputVector[k].tokenString[j]))
					{
						clear();
						return false;
					}
				}
			}
		}
		if (tokenizedInputVector[k].tokenType != CONTENT)
		{
			if (tokenizedInputVector[k].tokenString[0] == '.' || tokenizedInputVector[k].tokenString[0] == '-' || isdigit(tokenizedInputVector[k].tokenString[0]) || isspace(stringInsideTriangle[k][0]))
			{
				return false;
			}
		}
	}

	// we have the type and the names now

	// for (int i = 0; i < tokenizedInputVector.size(); i++)
	//{
	//	cout << stringInsideTriangle[i] << endl;
	//	cout << tokenizedInputVector[i].tokenString << endl;
	//	cout << tokenizedInputVector[i].tokenType << endl;
	// }

	return true;
} // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	if(tokenizedInputVector.size() == 0){
		return false;
	}

	string currentStart;

	for (int i = 0; i < tokenizedInputVector.size(); i++)
	{
		if (tokenizedInputVector[i].tokenType != DECLARATION && tokenizedInputVector[i].tokenType != CONTENT && tokenizedInputVector[i].tokenType != EMPTY_TAG)
		{
			if (tokenizedInputVector[i].tokenType == START_TAG)
			{
				stackStack->push(tokenizedInputVector[i].tokenString);
				currentStart = tokenizedInputVector[i].tokenString;
			}
			else if(tokenizedInputVector[i].tokenType == END_TAG){
				stackStack->push(tokenizedInputVector[i].tokenString);
			}
			if (stackStack->peek() == currentStart && tokenizedInputVector[i].tokenType == END_TAG)
			{
				stackStack->pop();
				stackStack->pop();
				if (stackStack->size() != 0)
				{
					currentStart = stackStack->peek();
				}
			}
		}
	}

	if (stackStack->size() != 0)
	{
		return false;
	}

	return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	tokenizedInputVector.clear();
	//delete elementNameBag;
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{

	if(tokenizedInputVector.size() == 0)
	{
		throw 
		(std::invalid_argument
		("to get element you cant have a 0 size Vector")
		);
		return false;
	
	}

	if (elementNameBag->contains(inputString))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if(tokenizedInputVector.size() == 0)
	{
		throw 
		(std::invalid_argument
		("to get frequency you cant have a 0 size Vector")
		);
		return false;
	}

	return elementNameBag->getFrequencyOf(inputString);
}
