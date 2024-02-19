#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

static void printVectorOfVector(const vector<vector<string>> &vec)
{
	for (const auto &innerVec : vec)
	{
		for (const auto &str : innerVec)
		{
			cout << str << " ";
		}
		cout << endl;
	}
}

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string &value)
{
	for (int i = 0; i < value.size(); i++)
	{
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string> candidateStringVector, vector<string> currentStringVector)
{
	
	if (currentStringVector.empty())
	{
		// Base case: concatenate candidate strings and check if it's a palindrome
		string candidateComb;
		for (const string &candidate : candidateStringVector)
		{
			candidateComb += candidate;
		}


		if (isPalindrome(candidateComb))
		{
			listPalindromes.push_back(candidateStringVector);
			numPalindromes++;
		}

		return;
	}

	// Recursive case: iterate over remaining strings and form combinations
	for (int i = 0; i < currentStringVector.size(); i++)
	{
		vector<string> newCandidate = candidateStringVector;
		vector<string> newCurrent = currentStringVector;

		newCandidate.push_back(newCurrent[i]);
		newCurrent.erase(newCurrent.begin() + i);

		// Recur with the updated candidate and current vectors
		recursiveFindPalindromes(newCandidate, newCurrent);
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i = 0; i < stringLength / 2; i++)
	{
		if (currentString[i] != currentString[stringLength - i - 1])
		{
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	mystringVector.clear();
	listPalindromes.clear();
	mystringVector.resize(0);
	listPalindromes.resize(0);
	numWords = 0;
	numPossible = 0; 
	numPalindromes = 0;
}

FindPalindrome::~FindPalindrome()
{
	// no memory stuff
}

int FindPalindrome::number() const
{
	return numPalindromes;
}

void FindPalindrome::clear()
{
	mystringVector.clear();
	listPalindromes.clear();
	mystringVector.resize(0);
	listPalindromes.resize(0);
	numWords = 0;
	numPossible = 0;
	numPalindromes = 0;
}

bool FindPalindrome::cutTest1(const vector<string> &stringVector)
{

	int charCount[128] = {0}; // 128 rows each counting as 1 ASCII character

	std::string stringConcatenated;
	for (int i = 0; i < stringVector.size(); i++)
	{ // concatenates string Vector into a string

		stringConcatenated += stringVector[i];
	}

	for (int i = 0; i < stringConcatenated.length(); i++)
	{
		unsigned char ch = tolower(stringConcatenated[i]); // make sure the range is 0-256 and not negative
		// increments the spot that holds the cahracter
		// ex. a = 97 in ASCII so charCount[97] == 1
		charCount[ch]++;
	}

	int odd = 0;
	int oddIndex = 0;
	for (int i = 0; i < 128; i++)
	{
		if ((charCount[i] % 2) != 0)
		{
			odd++;
			oddIndex = i;
		}
	}
	if (odd == 1)
	{

		int sum = 0;
		for (int j = 0; j < 128; j++) //**SINCE ADD CALLS CUT TEST WE NEED TO ACCOUNT FOR THE CHAR COUNT TO BE 1 ODD LETTER
		{
			sum += charCount[j];
		}

		if (sum == 1)
		{
			return true;
		}

		// check if the odd one comes in the center of the string

		// WHY IS THIS NOT GOOD

		// if (char(oddIndex) != stringConcatenated[stringConcatenated.length() / 2]) // char(oddIndex) returns the ASCII letter of the index
		//{
		//	return false;
		// }

		// WHY IS THIS NOT GOOD
	}

	if (odd > 1)
	{
		return false;
	}

	return true;
}

bool FindPalindrome::cutTest2(const vector<string> &stringVector1,
							  const vector<string> &stringVector2)
{
	int charCount1[256] = {0};
	int charCount2[256] = {0};
		
	vector<string> shorter = stringVector1;
	vector<string> longer = stringVector2;

	if(stringVector1.size()<stringVector2.size()){
		 shorter = stringVector1;
		longer = stringVector2;
	}
	else{
		shorter = stringVector2;
		longer = stringVector1;
	}

	// Count characters in stringVector1
	for (const std::string &str : shorter)
	{
		for (char ch : str)
		{
			ch = std::tolower(ch); // Convert to lowercase for case insensitivity
			charCount1[(unsigned char)ch]++;
		}
	}

	// Count characters in stringVector2
	for (const std::string &str : longer)
	{
		for (char ch : str)
		{
			ch = std::tolower(ch); // Convert to lowercase for case insensitivity
			charCount2[(unsigned char)ch]++;
		}
	}

	
	for (int i = 0; i < 256; i++)
	{
		if (charCount1[i] > charCount2[i])
		{
			return false;
		}
	}

	return true;
}

bool FindPalindrome::add(const string &value)
{
	// Check if the value contains only alphabetical characters
	for (int i = 0; i < value.length(); i++)
	{
		if (!isalpha(value[i]))
		{
			return false;
		}
	}

	// Check if adding the value maintains the palindrome structure
	vector<string> tempVectString;
	tempVectString.push_back(value);

	/*
	if (!cutTest1(tempVectString))
	{
		return false;
	}
	*/
	// Check if the value is already present in mystringVector
	for (const string &existingString : mystringVector)
	{
		// Convert both strings to lowercase for comparison
		string lowercaseExisting = existingString;
		string lowercaseValue = value;
		convertToLowerCase(lowercaseExisting);
		convertToLowerCase(lowercaseValue);

		if (lowercaseExisting == lowercaseValue)
		{
			return false;
		}
	}

	// Add the value to mystringVector and update other variables
	mystringVector.push_back(value);
	numWords++;
	numPossible = numWords;

	for (size_t i = 1; i < numWords; i++)
	{
		numPossible *= i;
	}

	// Recalculate palindromes
	vector<string> temp3;
	temp3.clear();
	numPalindromes = 0;
	listPalindromes.clear();
	listPalindromes.resize(0);
	recursiveFindPalindromes(temp3, mystringVector);

	return true;
}

bool FindPalindrome::add(const vector<string> &stringVector)
{

	for (int i = 0; i < stringVector.size(); i++)    
	{
		string tempString = stringVector[i]; //gets the first word of string vector
		int tempStringSize = tempString.length();

		for (int j = 0; j < tempStringSize; j++)
		{
			if (!isalpha(tempString[j]))
			{
				return false;
			}
		}

		string tempString2 = tempString; //copies tempString into tempString 2 to preserve case
		convertToLowerCase(tempString2);

		for(int k =0; k<mystringVector.size();k++){ //compares all of my string Vector's words with one word from the passed in vector

			string tempString3 = mystringVector[k]; //gets the first word of my string VEctor
			convertToLowerCase(tempString3);

			if(tempString2 == tempString3){
				return false;
			}

		}

		mystringVector.push_back(tempString); //if the words don't match and arent non alphabetic add it onto the string			
	}
	/*
	if (!cutTest1(stringVector))
	{
		return false;
	}
*/
	vector<string> temp3;
	temp3.clear();
	numPalindromes = 0;
	listPalindromes.clear();
	listPalindromes.resize(0);
	recursiveFindPalindromes(temp3, mystringVector);

	return true;
}

vector<vector<string>> FindPalindrome::toVector() const
{
	printVectorOfVector(listPalindromes);

	return listPalindromes;
}
