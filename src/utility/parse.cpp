#include "parse.h"

#include <iostream>

#include "filehandling.h"

void Parse(std::wstringstream input, Dictionary* dictionary)
{
	/*
		While there is still text to iterate over.
	*/
	std::wstring line;
	while (std::getline(input, line))
	{
		/*
			If we're dealing with one of the first
			two header lines, we can just ignore it.
		*/
		if (line[0] == L'\n') continue;
		if (line[0] == L'#' && line[2] != L't') continue;

		/*
			This is a really janky way of checking if
			our line starts with "# text" but it works
			so I'm not going to complain.
		*/
		if (line[0] == L'#')
		{
			std::wstring sentence = L"";
			for (int i = 9; i < line.size(); i++) sentence += line[i];
			dictionary->AddSentence(sentence);
			continue;
		}

		/*
			If we're here, we're dealing with a
			word-line which means we should grab
			all the text between the first and
			second tabs.
		*/
		bool hit = false;
		std::wstring word = L"";
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == L'\t')
			{
				if (hit) break;
				hit = true;
				continue;
			}

			if (hit) word += line[i];
		}

		// Just to be safe.
		if (word == L"") continue;

		// And now we add it to the dictionary.
		dictionary->AddWord(word);
	}
}