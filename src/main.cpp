/*
	main.cpp
*/

#include <iostream>

#include "data/maxmatch.h"
#include "utility/filehandling.h"
#include "utility/parse.h"

void main()
{
	Dictionary* testDictionary = new Dictionary();
	Dictionary* trainDictionary = new Dictionary();

	Parse(ReadFile("datasets/input/ja_gsd-ud-test.conllu"), testDictionary);
	Parse(ReadFile("datasets/input/ja_gsd-ud-train.conllu"), trainDictionary);

	std::cout << "The test dictionary has " << testDictionary->GetSize() << " terms.\n";
	std::wcout << L"The train dictionary has " << trainDictionary->GetSize() << L" terms.\n";

	std::vector<std::wstring> test = Tokenize(testDictionary->GetSentence(0), trainDictionary);

	std::wstring output = L"";
	for (int i = 0; i < test.size(); i++) output += test[i] + L" ";

	WriteFile("datasets/output/test.txt", output);
}