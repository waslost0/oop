#include <iostream>
#include <fstream>
#include <optional>
#include <string>

const std::string INVALID_ARGUMENTS = "Invalid arguments count\nUsage: copyfile.exe <input file> <output file>\n";
const std::string SAVE_FAIL = "Failed to save data on disk\n";

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << INVALID_ARGUMENTS;
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}


int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return EXIT_FAILURE;
	}

	std::ifstream input(args->inputFileName);

	if (!input.is_open())
	{
		std::cout << "Failed to open " << args->inputFileName << " for reading\n";
		return 1;
	}

	std::ofstream output(args->outputFileName);
	if (!output.is_open())
	{
		std::cout << "Failed to open " << args->outputFileName<< " for writing\n";
		return 1;
	}

	char ch;

	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			std::cout << SAVE_FAIL;
			return 1;
		}
	}

	if (!output.flush())
	{
		std::cout << SAVE_FAIL;
		return 1;
	}

	return 0;
}