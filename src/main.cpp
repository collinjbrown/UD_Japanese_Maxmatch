/*
	main.cpp
*/

#include <iostream>
#include <chrono>

#include "data/maxmatch.h"
#include "utility/filehandling.h"
#include "utility/parse.h"

void main()
{
	auto start = std::chrono::high_resolution_clock::now();

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
		std::wstring ref = L"";
		std::wstring hyp = L"";

		std::wstring fullref = testDictionary->GetSentence(i);
		for (int i = 0; i < fullref.size(); i++) if (fullref[i] != L' ') ref += fullref[i];

		std::vector<std::wstring> out = Tokenize(ref, trainDictionary);

		for (int j = 0; j < out.size(); j++)
		{
			hyp += out[j];
			if (j < out.size() - 1) hyp += L"\t";
		}

		hypothesis += hyp;
		reference += fullref;

		if (i < sentenceCount - 1)
		{
			reference += L"\n";
			hypothesis += L"\n";
		}
	}

	WriteFile("datasets/output/reference.txt", reference);
	WriteFile("datasets/output/hypothesis.txt", hypothesis);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::wcout << L"Execution took " << duration.count() << L" microseconds.\n";
}