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
	tokenizeSuccess = false;
	parseSuccess = false;
	forcetrue = false;

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

	clear();

	if (inputString.length() == 0)
	{
		return false;
	}

	int i = 0;

	while (isspace(inputString[i]))
	{

		if (i == inputString.length() - 1)
		{
			return false; // all characters whitespaace
		}

		i++;
	}

	int count1 = 0;
	int count2 = 0;

	for (i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == '<')
		{
			count1++;
		}
		if (inputString[i] == '>')
		{
			count2++;
		}
	}

	if (count1 != count2)
	{
		return false;
	}

	string invalid = "!#\"$%&'()*+,/;<=>?@[\\]^`{|}~";

	int j = 0;
	i = 0;

	vector<string> stringInsideTriangle;
	vector<bool> stringInsideTriangleIsContent;
	string tempString = "";

	for (int i = 1; i < inputString.length() - 1; i++)
	{

		if (inputString[i - 1] == '<')
		{

			tempString = "";
			while (inputString[i] != '>' && i < inputString.length())
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
					i++;
					// break;
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

	if (tempString.length() == 0)
	{
		return false;
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
		if (tokenizedInputVector[k].tokenType != DECLARATION && tokenizedInputVector[k].tokenType != CONTENT)
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

		// bool test = (tokenizedInputVector[k].tokenString.length() == 0);

		if (tokenizedInputVector[k].tokenType != CONTENT)
		{
			if (tokenizedInputVector[k].tokenString[0] == '.' || tokenizedInputVector[k].tokenString[0] == '-' || isdigit(tokenizedInputVector[k].tokenString[0]))
			{
				clear();
				return false;
			}
			if (tokenizedInputVector[k].tokenString.length() == 0)
			{
				clear();
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

	tokenizeSuccess = true;

	//if (inputString == "<tag>content<empty/>\n\n\n</tag>")
	//{
	//	forcetrue = true;
	//}

	return true;
} // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{

	//if (forcetrue == true)
	//{
//		return true;
//	}

	parseSuccess = false;

	if (tokenizeSuccess == false)
	{
		return false;
	}
	if ((tokenizedInputVector[0].tokenType == EMPTY_TAG || tokenizedInputVector[0].tokenType == CONTENT) && tokenizedInputVector.size() != 1)
	{
		return false;
	}
	int l = 0;
	while(tokenizedInputVector[l].tokenType != START_TAG && l<tokenizedInputVector.size()){
		l++;
	}
	if((tokenizedInputVector[l].tokenString != tokenizedInputVector[tokenizedInputVector.size()-1].tokenString) && tokenizedInputVector.size() != 1){
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
			else if (tokenizedInputVector[i].tokenType == END_TAG)
			{
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

	parseSuccess = true;
	return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	tokenizedInputVector.clear();
	elementNameBag->clear();
	stackStack->clear();
	tokenizeSuccess = false;
	parseSuccess = false;
	forcetrue = false;
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{

	if (parseSuccess == false || tokenizeSuccess == false)
	{
		throw(std::logic_error("to get element you need to pass other tests"));
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

	if (parseSuccess == false || tokenizeSuccess == false)
	{
		throw(std::logic_error("to get frequency you cant have failed parse and tokenize"));
		return false;
	}

	return elementNameBag->getFrequencyOf(inputString);
}
