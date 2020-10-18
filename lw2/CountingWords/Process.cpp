#include "Process.h"

WordCounting CountWord(std::string& str)
{
	WordCounting word;
	std::istringstream iss(str);

	while (iss >> str)
	{
		std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
		++word[str];
	}

	return word;
}