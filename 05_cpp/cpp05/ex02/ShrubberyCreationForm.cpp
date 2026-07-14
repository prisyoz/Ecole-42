#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :  AForm(src), _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::action() const
{
	std::ofstream	file((_target + "_shrubbery").c_str());

	if ((!file.is_open()))
		std::cerr << "Error: Could not open or create file." << std::endl;
	
	file << "     *     \n";
	file << "    ***    \n";
	file << "   *****   \n";
	file << "  *******  \n";
	file << "***********\n";
	file << "   |||||   \n";
	file << "   |||||   \n";
	file << " Shubbery" << std::endl;
}