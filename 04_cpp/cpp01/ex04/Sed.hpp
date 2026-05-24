#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

std::string ReplacedContent(std::string content, std::string s1, std::string s2);
bool 		FileExist(const std::string& file);

#endif