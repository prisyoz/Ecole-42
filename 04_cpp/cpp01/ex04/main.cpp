#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Only 3 parameters" << std::endl;
		return 1;
	}

	std::string	file = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	
	// Error handling for string
	if (s1.length() == 0)
	{
		std::cerr << "Error, empty string\n" << std::endl;
		return 1;
	}

	// open Input
	std::ifstream oriFile(file.c_str());
	if (!oriFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return 1;
	}

	// new file
	std::string	NewFile = file + ".replace";
	std::ofstream outFile(NewFile.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		return 1;
	}

	// open filename
	std::string	line;

	while(std::getline(oriFile, line))
	{
		std::string newContent = ReplacedContent(line, s1, s2);
		outFile << newContent;
		if (!oriFile.eof())
			outFile << "\n";
	}
	oriFile.close();
	outFile.close();

	return (0);
}
