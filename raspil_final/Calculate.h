#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

void CutFirstElement(std::vector<int> & parts, const int & num); //cut first element of vector and push into its begin two little pieces

size_t ComputeCutsCost(const int & l, const int & n, const bool & isFirstCutHalf); //if isFirstCutHalf == false -  for first, cut block with size == N.

size_t ComputeResultCost(const int & l, const int & n);