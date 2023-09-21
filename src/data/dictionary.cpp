#include "dictionary.h"

/*------------------------------------------*/
/* Good Ol' Diccionario                     */
/*------------------------------------------*/
/*--------------------------------*/
/* General Functions              */
/*--------------------------------*/
void Dictionary::AddWord(std::wstring word)
{
	if (frequencyMap.find(word) != frequencyMap.end())
	{
		frequencyMap[word]++;
		return;
	}

	size++;
	frequencyMap.emplace(word, 1);
}

unsigned int Dictionary::GetFrequency(std::wstring word)
{
	if (frequencyMap.find(word) != frequencyMap.end())
	{
		return frequencyMap[word];
	}

	return 0;
}

void Dictionary::AddSentence(std::wstring sentence)
{
	sentences.push_back(sentence);
}