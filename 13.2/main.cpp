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
позиций в строке начинается с 1. Если вхождений нет, вывести No.*/


using namespace std;


int main(int argc, char * argv[])
{
//    	argc = 2;
//    	argv[1] = "tests/test_2_input.txt";
	if (argc != 2)
	{
		std::cout << "incorrect program execution.\nExample: 13.2.exe <inputFile>" << std::endl;
		return 4;
	}

	ifstream mainInputFile(argv[1]);
	if (!mainInputFile.is_open())
	{
		std::cout << "Could not open main inputFile" << std::endl;
		return 3;
	}

	std::string pattern;  //searchingWord
	std::getline(mainInputFile, pattern);
	std::string textInputFileName;
	std::getline(mainInputFile, textInputFileName);

	ofstream outputFile("output.txt");
	if (!outputFile.is_open())
	{
		std::cout << "OutputFile cannot be opened" << std::endl;
	}

	ifstream textInputFile(textInputFileName);


	if (pattern.empty() || pattern.length() > 255 ||textInputFileName.empty()) //if input is incorrect (empty word or fileName)
	{
		outputFile << "Error: incorrect inputFile";
		return 1;
	}
	if (!textInputFile.is_open())
	{
		outputFile << "Error: Couldn't open textFile";
		return 2;
	}

	vector<std::pair<size_t, size_t>> result = StartKMP(textInputFile, pattern); //calculate result(indexes of lines and indexes of found words as pairs
	WriteResultInFile(outputFile,result);

	return 0;
}