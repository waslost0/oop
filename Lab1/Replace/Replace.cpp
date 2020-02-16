#include <iostream>
#include <optional>
#include <fstream>
#include <string>


struct Args
{
	std::string inputFileName;
	std::string outputFileName;
	std::string searchString = "";
	std::string replaceString = "";
	unsigned int argsCount = 2;
};


std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc > 5 || argc < 3)
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return std::nullopt;
	}
	
	if (strcmp(argv[1], argv[2]) == 0) {
		std::cout << "Invalid arguments.\nFiles cannot be equal."
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return std::nullopt;
	}

	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];

	if (argc > 3)
	{
		args.searchString = argv[3];
		args.argsCount = 3;
	}

	if (argc > 4)
	{
		args.argsCount = 4;
		args.replaceString = argv[4];
	}

	return args;
}


int EmptyReplace(std::optional<Args>& args, std::ifstream& inputFile, std::ofstream& output)
{
	if (args->argsCount == 2)
	{
		std::string inputLine;
		while (std::getline(inputFile, inputLine))
		{
			output << inputLine << std::endl;
		}
	}
	return EXIT_FAILURE;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return EXIT_FAILURE;
	}

	std::ifstream inputFile(args->inputFileName);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
		return EXIT_FAILURE;
	}

	std::ofstream output(args->outputFileName);
	if (!output.is_open())
	{
		std::cout << "Failed to open " << args->outputFileName << " for writing\n";
		return EXIT_FAILURE;
	}

	EmptyReplace(args, inputFile, output);

	std::string inputLine;

	while (std::getline(inputFile, inputLine))
	{
		std::string newLine;
		while (inputLine != "")
		{
			size_t insertPos = inputLine.find(argv[3]);
			newLine.append(inputLine, 0, insertPos);
			if (insertPos != -1)
			{
				inputLine.erase(0, insertPos + args->searchString.length());
				newLine += args->replaceString;
			}
			else
			{
				break;
			}
		}
		output << newLine << std::endl;
	}
}
