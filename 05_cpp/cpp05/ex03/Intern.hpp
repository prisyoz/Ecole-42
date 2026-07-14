#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& original);
		Intern& operator=(const Intern& original);
		~Intern();

		AForm*	makeForm(std::string form, std::string target);
};



#endif