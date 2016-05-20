#include <fstream>
#include <iostream>
#include "KMP.h"


using namespace std;



int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "incorrect program execution.\nExample: 13.2.exe <inputFile>" << std::endl;
		return 2;
	}

	ifstream mainInputFile("input.txt");
	if (!mainInputFile.is_open())
	{
		std::cout << "Could not open main inputFile" << std::endl;
		return 3;
	}
	std::string pattern;
	std::getline(mainInputFile, pattern);
	std::string textInputFileName;
	std::getline(mainInputFile, textInputFileName);

	if (pattern.empty() | textInputFileName.empty())
	{
		std::cout << "incorrect input" << std::endl;
		return 1;
	}
	ifstream textInputFile(textInputFileName);
	if (!textInputFile.is_open())
	{
		std::cout << "Could not open textFile" << std::endl;
		return 3;
	}

	ofstream outputFile("output.txt");
	if (!outputFile.is_open())
	{
		std::cout << "OutputFile cannot be opened" << std::endl;
	}
	outputFile << StartKMP(textInputFile, pattern) << std::endl;
	return 0;
}