#include "Calculate.h"


void CutFirstElement(std::vector<int> & parts, const int & firstElementSize)
{
	parts.erase(parts.begin());
	int biggerPart = firstElementSize - firstElementSize / 2;
	int lowerPart = firstElementSize - biggerPart;

	if (biggerPart % 2 == 0)
	{
		parts.insert(parts.begin(), biggerPart);
	}
	else
	{
		parts.push_back(biggerPart);
	}
	if (lowerPart % 2 == 0)
	{
		parts.insert(parts.begin(), lowerPart);
	}
	else
	{
		parts.push_back(lowerPart);
	}
}

size_t ComputeCutsCost(const int & l, const int & n, const bool & isFirstCutHalf)
{
	int totalCost;
	size_t count;
	std::vector<int> parts;

	if (isFirstCutHalf) //if we cut half first
	{
		parts.push_back(l); //will cut all the length
		totalCost = 0;
		count = 0;
	}
	else //if we firstly cut not half, but N-size.
	{
		parts.push_back(n); //will cut just n-size block
		totalCost = l;
		count = 1;
	}


	while (count < n)
	{
		if (!parts.empty() && parts[0] > 1)
		{
			int firstElementSize = parts[0];
			CutFirstElement(parts, firstElementSize);
			count++;
			totalCost += firstElementSize;
			if (parts.size() == 1)
			{
				count++;
				totalCost += firstElementSize;
			}
		}
		else if (!parts.empty()) //if first element is '1' - so it's impossible to cut, just delete it from the vector.
		{
			parts.erase(parts.begin());
		}
	}

	return totalCost;
}

size_t ComputeResultCost(const int & l, const int & n)
{
	if (n * 2 > l)
	{
		return std::min(ComputeCutsCost(l, n, false), ComputeCutsCost(l, n, true));
	}
	return ComputeCutsCost(l, n, false);
}