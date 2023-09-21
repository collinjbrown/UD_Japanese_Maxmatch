#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <unordered_map>

/*------------------------------------------*/
/* Good Ol' Diccionario                     */
/*------------------------------------------*/
class Dictionary
{
private:
	/*--------------------------------*/
	/* General                        */
	/*--------------------------------*/
	unsigned int	size = 0;
	unsigned int	maxSize = 20000;

	/*--------------------------------*/
	/* Sentences                      */
	/*--------------------------------*/
	std::vector<std::wstring>	sentences;

	/*--------------------------------*/
	/* Maps                           */
	/*--------------------------------*/
	std::unordered_map<std::wstring, unsigned int>	frequencyMap;

public:
	/*--------------------------------*/
	/* General Functions              */
	/*--------------------------------*/
	unsigned int	GetSize() { return size; }

	void			AddWord(std::wstring word);
	unsigned int	GetFrequency(std::wstring word);

	void			AddSentence(std::wstring sentence);
};

#endif