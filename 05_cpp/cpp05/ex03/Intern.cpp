/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:18:33 by pang              #+#    #+#             */
/*   Updated: 2026/07/09 16:20:09 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& original)
{
	*this = original;
}

Intern& Intern::operator=(const Intern& original)
{
	(void)original;
	return (*this);
}

Intern::~Intern() {}

static AForm*	createShrubbery(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm*	createRobotomy(const std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	createPresident(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	std::string	formType[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreate[3])(const std::string) = 
	{
		createShrubbery,
		createRobotomy,
		createPresident
	};

	for (int i = 0; i < 3; i++)
	{
		if (form == formType[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return (formCreate[i])(target);
		}
	}

	std::cout << "Error: Intern cannot create form " << form
		<< " because it doesn't exist" << std::endl;

	return NULL;
}