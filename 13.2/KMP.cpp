#include "KMP.h"


/*
SymbolType GetLetterType(const char & letter)
{
	if (letter < 91 && letter > 64)
	{
		return ENGLISH_UPPER_CASE;
	}
	if (letter > 96 && letter < 123)
	{
		return ENGLISH_LOWER_CASE;
	}
	if (letter < 224 && letter > 191)
	{
		return RUSSIAN_UPPER_CASE;
	}
	if (letter > 223 && letter < 256)
	{
		return RUSSIAN_LOWER_CASE;
	}
	return OTHER;
}
*/
/*
bool AreEqualLetters(const char & first, const char & second)
{
	if (GetLetterType(first) == GetLetterType(second) ||
		GetLetterType(first) == ENGLISH_UPPER_CASE && GetLetterType(second) == ENGLISH_LOWER_CASE ||
		GetLetterType(first) == RUSSIAN_UPPER_CASE && GetLetterType(second) == RUSSIAN_LOWER_CASE ||
		GetLetterType(first) == OTHER && GetLetterType(second) == OTHER)
	{
		return true;
	}

	return false;
}
*/

vector<int> ComputePrefixFunction(const string & pattern)
{
	vector<int> prefixFunction(pattern.length());
	prefixFunction[0] = 0;
	int k = 0;
	for (size_t i = 1; i < pattern.length(); i++)
	{
		while ((k > 0) && (tolower(pattern[k]) != tolower(pattern[i])))
		{
			k = prefixFunction[k - 1];
		}
		if (tolower(pattern[k]) == tolower(pattern[i]))
		{
			k++;
		}
		prefixFunction[i] = k;
	}
	return prefixFunction;
}


size_t KMP(const string & text, const string & pattern, const int & beginIndex, size_t & count)  
{
	vector<int> prefixFunction = ComputePrefixFunction(pattern);

	int k = 0;
	for (size_t i = beginIndex; i < text.length(); ++i)
	{
		while ((k > 0) && (tolower(pattern[k]) != tolower(text[i])))
		{
			k = prefixFunction[k - 1];
		}
		if (tolower(pattern[k]) == tolower(text[i]))
		{
			k++;
		}
		if (k == pattern.length())  //if (words are equal) or if word ends with space and it's end of line
		{
			count++;
			return (i - pattern.length() + 2);
		}
		else if (pattern[pattern.length() - 1] == ' ' && k == pattern.length() - 1 && (i == text.length() - 1))
		{
			count++;
			return (i - pattern.length() + 3);
		}

	}

	return string::npos;
}

vector<std::pair<size_t, size_t>> StartKMP(ifstream & inputFile, const std::string & pattern)
{
	vector<std::pair<size_t,size_t>> result;
	std::string line;
	size_t lineCount = 1;
	size_t wordCount = 0;
	size_t nextPos = 0;

	while (std::getline(inputFile, line))
	{
		while (nextPos >= 0)
		{
			nextPos = KMP(line, pattern, nextPos, wordCount);
			if (nextPos == string::npos)
			{
				break;
			}
			result.push_back(std::pair<size_t, size_t>(lineCount, nextPos));
		}
		nextPos = 0;
		lineCount++;
	}
	
	return result;
}

void WriteResultInFile(ofstream & outputFile, const vector<std::pair<size_t, size_t>> & result)
{
	if (result.empty())
	{
		outputFile << "No";
	}
	else
	{
		bool isFirstLine = true;
		for (auto element : result)
		{
			if (isFirstLine)
			{
				isFirstLine = false;
			}
			else outputFile << "\n";

			outputFile << element.first << " " << element.second;
		}
	}

	if (!outputFile.flush())
	{
		std::cout << "Error closing outputFile";
	}
}