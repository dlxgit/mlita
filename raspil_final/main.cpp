#include "Calculate.h"

/*
14.10. Распил бруса 2 (10)
На пилораму привезли брус длиной L метров. Требуется сделать N распилов. Распилы делят брус на части, длина которых выражается натуральными числами. Стоимость одного распила равна длине распиливаемого бруса. Определить минимальную стоимость распила.
Ввод. В первой строке содержатся через пробел натуральные числа L (2 ≤ L ≤ 105) и N (N < L) – длина бруса и число распилов.
Вывод. В единственной строке вывести минимальную стоимость распилов.
*/

using namespace std;

bool ReadFromFile(const std::string & inputFileName, int & l, int & n)
{
	ifstream inputFile(inputFileName);
	inputFile >> l;
	inputFile >> n;
	if (l > 10000 || l < 2 || n >= l)
	{
		std::cout << "Error: incorrect input" << std::endl;
		return false;
	}
	return true;
}


int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: incorrect usage." << std::endl;
	}

	ofstream outputFile("output.txt");
	int l; //length
	int n; //number of cuts
	if (!ReadFromFile(argv[1], l, n))
	{
		return 1;
	}
	outputFile << ComputeResultCost(l, n);
	outputFile.close();
	return 0;
}