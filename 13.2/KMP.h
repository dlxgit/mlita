#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;


vector<int> ComputePrefixFunction(const string & s);

size_t KMP(const string & S, const string & pattern, const int & beginIndex, size_t & count); //возвращает следующий после найденного вхождения индекс

size_t StartKMP(ifstream & inputFile, const std::string & pattern);