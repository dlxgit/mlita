#include "KMP.h"


vector<int> ComputePrefixFunction(const string & s)
{
	int len = s.length();
	vector<int> p(len); // значения префикс-функции
						// индекс вектора соответствует номеру последнего символа аргумента
	p[0] = 0; // для префикса из нуля и одного символа функция равна нулю

	int k = 0;
	for (int i = 1; i < len; i++)
	{
		while ((k > 0) && (s[k] != s[i]))
		{
			k = p[k - 1];
		}
		if (s[k] == s[i])
		{
			k++;
		}
		p[i] = k;
	}
	return p;
}


size_t KMP(const string & text, const string & pattern, const int & beginIndex, size_t & count)  
{
	vector<int> prefixFunction = ComputePrefixFunction(pattern);

	int k = 0;
	for (size_t i = beginIndex; i < text.length(); ++i)
	{
		while ((k > 0) && (pattern[k] != text[i]))
		{
			k = prefixFunction[k - 1];
		}
		if (pattern[k] == text[i])
		{
			k++;
		}
		if (k == pattern.length())
		{
			count++;
			return (i - pattern.length() + 2);
		}
	}

	return (string::npos);
}

size_t StartKMP(ifstream & inputFile, const std::string & pattern)
{
	std::string line;
	size_t count = 0;
	size_t nextPos = 0;
	while (std::getline(inputFile, line))
	{
		while (nextPos >= 0 && nextPos < string::npos)
		{
			nextPos = KMP(line, pattern, nextPos, count);
		}
	}
	return count;
}