// HTMLDecode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Decode.h"


int main()
{
	std::string str;
	while (std::getline(std::cin, str))
	{
		std::string decodedString = HtmlDecode(str);
		std::cout << decodedString << std::endl;
	}
}
