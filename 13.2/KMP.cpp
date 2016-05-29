#include "KMP.h"


std::string ReadPatternFromFile(ifstream & inputFile)
{
	string pattern;
	std::getline(inputFile, pattern);
	std::string resultString;
	for (size_t i = 0; i < pattern.length(); i++)
	{
		if (pattern[i] == '\\' && pattern.size() > i + 1 && pattern[i + 1] == 'n')
		{
			resultString += '\n';
			i += 1;
		}
		else
		{
			resultString += pattern[i];
		}
	}
	return resultString;
}

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

size_t KMP(const vector<int> & prefixFunction, const string & text, const string & pattern, const vector<size_t> & stringSizeList, const int & beginIndex)  
{
	int k = 0;
	for (size_t i = beginIndex; i < text.length(); ++i)
	{
		while ((k > 0) && (tolower(pattern[k]) != tolower(text[i]) && !(pattern[k] == ' ' && text[i] == '\n'))) //while not match
		{
			k = prefixFunction[k - 1];
		}
		if (tolower(pattern[k]) == tolower(text[i]) || pattern[k] == ' ' && text[k] == '\n')
		{
			k++;
		}
		if (k == pattern.length())  
		{
			return (i - pattern.length() + 2);
		}
		else if (pattern[pattern.length() - 1] == ' ' && text[i] == '\n' && (k == pattern.length() - 1)) //if (words are equal) or if word ends with space and it's end of line
		{
			return (i - pattern.length() + 2);
		}
	}

	return string::npos;
}

std::pair<size_t, size_t> ComputeSymbolPositionInText(const size_t & index, vector<size_t> & stringSizeList)
{
	size_t pos = 0;
	std::pair<size_t, size_t> result;
	for (size_t i = 0; i < stringSizeList.size(); i++)
	{
		if (pos + stringSizeList[i] + i > index)
		{
			result.first = i + 1;
			result.second = index - pos - i;
			break;
		}
		else
		{
			pos += stringSizeList[i];
		}
	}
	return result;
}

vector<std::pair<size_t, size_t>> ComputeResultOfKMPSearch(ifstream & inputFile, const std::string & pattern)
{
	vector<std::pair<size_t,size_t>> result;
	vector<size_t> stringSizeList;
	std::string line;
	size_t lineCount = 1;
	size_t wordCount = 0;
	size_t nextPos = 0;

	string text;

	while (std::getline(inputFile, line))
	{
		stringSizeList.push_back(line.size());
		text.append(line + '\n');
	}

	vector<int> prefixFunction = ComputePrefixFunction(pattern);

	while (nextPos >= 0)
	{
		nextPos = KMP(prefixFunction, text, pattern, stringSizeList, nextPos);
		if (nextPos == string::npos)
		{
			break;
		}
		result.push_back(ComputeSymbolPositionInText(nextPos, stringSizeList));
	}
	return result;
}

void WriteResultInFile(ofstream & outputFile, const vector<std::pair<size_t, size_t>> & result)
{
	if (result.empty())
	{
		outputFile << "No";
		return;
	}

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

	if (!outputFile.flush())
	{
		std::cout << "Error closing outputFile";
	}
}