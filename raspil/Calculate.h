#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional> 

void SortVector(std::vector<int> & parts, const int & nextCutCost);

size_t ComputeResult(int l, int n, bool isCommonCalculate = false);