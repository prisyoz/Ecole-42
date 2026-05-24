#include "Sed.hpp"

std::string ReplacedContent(std::string line, std::string s1, std::string s2)
{
	std::string	newLine = "";
	size_t		start = 0;
	size_t		end = line.find(s1);

	while (end != std::string::npos)
	{
		newLine += line.substr(start, end - start);
		newLine += s2;
		start = end + s1.length();
		end = line.find(s1, start);
	}
	newLine += line.substr(start);
	return (newLine);
}
