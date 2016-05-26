#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;



vector<int> ComputePrefixFunction(const string & pattern);

size_t KMP(const string & S, const string & pattern, const int & beginIndex, size_t & count); //возвращает следующий после найденного вхождения индекс

vector<std::pair<size_t,size_t>> StartKMP(ifstream & inputFile, const std::string & pattern);

void WriteResultInFile(ofstream & outputFile, const vector<std::pair<size_t, size_t>> & result);