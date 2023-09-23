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

	Parse(ReadFile("datasets/input/test.conllu"), testDictionary);
	Parse(ReadFile("datasets/input/train.conllu"), trainDictionary);

	std::wcout << L"The test dictionary has " << testDictionary->GetSize() << L" terms.\n";
	std::wcout << L"The train dictionary has " << trainDictionary->GetSize() << L" terms.\n";

	/*
		Now, we're going to run through the test data and see how
		our tokenizer performs.
	*/
	std::wstring reference = L"";
	std::wstring hypothesis = L"";

	unsigned int sentenceCount = testDictionary->GetSentenceCount();

	for (int i = 0; i < sentenceCount; i++)
	{
		std::wstring ref = testDictionary->GetSentence(i);
		std::wstring hyp = L"";

		std::vector<std::wstring> out = Tokenize(ref, trainDictionary);

		for (int j = 0; j < out.size(); j++)
		{
			hyp += out[j];
			if (j < out.size() - 1) hyp += L"\t";
		}

		hypothesis += hyp;
		reference += ref;

		if (i < sentenceCount - 1)
		{
			reference += L"\n";
			hypothesis += L"\n";
		}
	}

	WriteFile("datasets/output/reference.txt", reference);
	WriteFile("datasets/output/hypothesis.txt", hypothesis);
}