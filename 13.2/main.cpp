#include <fstream>
#include <iostream>
#include "KMP.h"

/*
13.2. Алгоритм Кнута – Морриса – Пратта (6)
Требуется найти все вхождения образца в текстовом файле методом КМП. В файле нет
переноса слов. Образец может включать пробелы и переходить с одной строки файла на другую.
Конец строки файла может интерпретироваться как пробел. Результаты поиска не должны
зависеть от регистра букв, то есть каждая буква в образце и файле может быть как строчной, так и
прописной.
Ввод из файла INPUT.TXT. Первая строка файла является образцом и имеет длину от 1 до 255.
Вторая строка задает имя текстового файла.
Вывод в файл OUTPUT.TXT. Вывести в каждой строке через пробел последовательность
номеров строк и позиций в строке, начиная с которых образец входит в текст. Нумерация строк и
позиций в строке начинается с 1. Если вхождений нет, вывести No.
*/


using namespace std;


int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "incorrect program execution.\nExample: 13.2.exe <inputFile>" << std::endl;
		return 4;
	}

	ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Could not open main inputFile" << std::endl;
		return 3;
	}

	std::string pattern = ReadPatternFromFile(inputFile); //searchingWord
	std::string textFileName;
	std::getline(inputFile, textFileName);

	ofstream outputFile("output.txt");
	if (!outputFile.is_open())
	{
		std::cout << "OutputFile cannot be opened" << std::endl;
	}

	ifstream textInputFile(textFileName);

	if (pattern.empty() || pattern.length() > 255 ||textFileName.empty()) //if input is incorrect (empty word or fileName)
	{
		cerr << "Error: incorrect inputFile" << std::endl;
		return 1;
	}
	if (!textInputFile.is_open())
	{
		cerr << "Error: couldn't open textFile" << std::endl;
		return 2;
	}

	vector<std::pair<size_t, size_t>> result = ComputeResultOfKMPSearch(textInputFile, pattern); //calculate result(indexes of lines and indexes of found words as pairs
	WriteResultInFile(outputFile,result);
	return 0;
}