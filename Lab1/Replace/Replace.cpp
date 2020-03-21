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

void CopyFileWithReplace(std::istream& input, std::ostream& output,
	const std::string& searchString, const std::string& replacementString)
{
	std::string inputLine;
	size_t lenSearchLine = searchString.length();
	while (std::getline(input, inputLine))
	{
		std::string newLine;
		size_t pos = 0;
		while (pos < inputLine.length())
		{
			size_t insertPos = inputLine.find(searchString, pos);
			newLine.append(inputLine, pos, insertPos - pos);
			if (insertPos != std::string::npos)
			{
				newLine.append(replacementString);
				pos = insertPos + lenSearchLine;
			}
			else
			{
				break;
			}
		}
		output << newLine << std::endl;
	}
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

	std::ofstream outputFile(args->outputFileName);
	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << args->outputFileName << " for writing\n";
		return EXIT_FAILURE;
	}

	if (args->argsCount == 2 || args->searchString == "")
	{
		std::string inputLine;
		while (std::getline(inputFile, inputLine))
		{
			outputFile << inputLine << std::endl;
		}
		return EXIT_SUCCESS;
	}


	CopyFileWithReplace(inputFile, outputFile, args->searchString, args->replaceString);

}
