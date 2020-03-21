#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <bitset>

const std::string ERROR_NUMBER = "Number must be in range (0, 255)\n";
const std::string ERROR_NOT_ENOUGH_ARGUMENTS = "Wrong input.\nExample:: flipbyte.exe <input byte>";

struct Args
{
	std::string numberStr;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << ERROR_NOT_ENOUGH_ARGUMENTS << std::endl;
		return std::nullopt;
	}
	Args args;
	args.numberStr = argv[1];
	return args;
}


int FlipByteInNumber(int& number)
{
	std::bitset<8> numInByte(number);

	auto reversedNumInByte = numInByte.to_string();
	std::reverse(reversedNumInByte.begin(), reversedNumInByte.end());

	auto reversedResultInByte = std::bitset<8>(reversedNumInByte);
	int reversedResult = (int)(reversedResultInByte.to_ulong());

	return reversedResult;
}

bool IsNumCorrect(std::string& line, int& number)
{
	try
	{
		number = std::stoi(line);
	}
	catch (const std::invalid_argument & err)
	{
		std::cerr << err.what() << std::endl;
		return false;
	}

	if (number < 0 || number > 255)
	{

		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return EXIT_FAILURE;
	}

	int number;

	if (!IsNumCorrect(args->numberStr, number))
	{
		std::cout << ERROR_NUMBER;
		return EXIT_FAILURE;
	}

	int result = FlipByteInNumber(number);
	std::cout << result << std::endl;
}