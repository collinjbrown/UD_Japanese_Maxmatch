/*
	main.cpp
*/

#include <iostream>
#include <locale>

#include "data/dictionary.h"
#include "utility/filehandling.h"
#include "utility/parse.h"

void main()
{
	Dictionary* dictionary = new Dictionary();

	Parse(ReadFile("datasets/input/ja_gsd-ud-train.conllu"), dictionary);
	std::cout << "The dictionary has " << dictionary->GetSize() << " terms.\n";


}