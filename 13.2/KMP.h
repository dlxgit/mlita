#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;


vector<int> ComputePrefixFunction(const string & pattern);

size_t KMP(const vector<int> & prefixFunction, const string & text, const string & pattern, const vector<size_t> & stringSizeList, const int & beginIndex); //возвращает следующий после найденного вхождения индекс

vector<std::pair<size_t,size_t>> ComputeResultOfKMPSearch(ifstream & inputFile, const std::string & pattern);

void WriteResultInFile(ofstream & outputFile, const vector<std::pair<size_t, size_t>> & result);

std::string ReadPatternFromFile(ifstream & inputFile);  // for correct '\n' in searching word