#include "stdafx.h"
#include "Calculate.h"


void SortVector(std::vector<int> & parts, const int & nextCutCost)
{
	int biggerPart = nextCutCost - nextCutCost / 2;
	int lowerPart = nextCutCost - biggerPart;

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

size_t ComputeResult(int l, int n, bool isCommonCalculate)
{
	int summ;
	size_t count;
	std::vector<int> parts;

	//if ( n > float(l) / 2)
	if(!isCommonCalculate)
	{
		parts = { l };
		summ = 0;
		count = 0;
	}
	else
	{
		parts = { n };
		summ = l;
		count = 1;
	}

	//while (count <= n)
	{
		//for (std::vector<int>::iterator it = parts.begin(); it != parts.end() && count < n;)
		while (count < n)
		{		
			int nextCutCost = *(parts.erase(parts.begin()));
			if (*parts.begin() > 1)
			{
				SortVector(parts, nextCutCost);
				count++;
				summ += nextCutCost;
				if (parts.size() == 1)
				{
					count++;
					summ += nextCutCost;
				}
			}
			else
			{
				parts.erase(parts.begin());
				//it++;
			}
		}
	}
	return summ;
}