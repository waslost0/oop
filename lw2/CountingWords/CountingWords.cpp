#include "Process.h"
#include <iostream>
#include <Windows.h>

void PrintCountWord(WordCounting& word)
{
	for (auto s : word)
	{
		std::cout << s.first << " -> " << s.second << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	std::string str;
	std::getline(std::cin, str);

	WordCounting word = CountWord(str);

	PrintCountWord(word);

	return 0;
}