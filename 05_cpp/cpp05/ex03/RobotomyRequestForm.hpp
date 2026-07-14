#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include <iostream>
#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& original);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& original);
		~RobotomyRequestForm();

		void	action() const;
};

#endif
