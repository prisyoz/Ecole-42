/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:17:50 by pang              #+#    #+#             */
/*   Updated: 2026/07/01 16:17:51 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// static void testBureaucrat(std::string name, int grade);
// static void testForm(std::string name, int signgrade, int execgrade);
static void	testSignForm(Bureaucrat& b, AForm& f);

int	main(void)
{
	srand(time(0));
	Bureaucrat	bur("bur", 150);
	Bureaucrat	cur("cur", 60);
	Bureaucrat	dur("dur", 20);
	Bureaucrat	fur("fur", 1);

	{
		std::cout << "=== BASIC TEST ===\n";
		
		std::cout << "\n--- bur test (150) ---\n";
		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robot("robot");
		PresidentialPardonForm	pres("pres");

		testSignForm(bur, shrub);
		testSignForm(bur, robot);
		testSignForm(bur, pres);
	}

	{
		std::cout << "\n--- cur test (60) ---\n";
		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robot("robot");
		PresidentialPardonForm	pres("pres");

		testSignForm(cur, shrub);
		testSignForm(cur, robot);
		testSignForm(cur, pres);
	}

	{
		std::cout << "\n--- dur test (60) ---\n";
		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robot("robot");
		PresidentialPardonForm	pres("pres");

		testSignForm(dur, shrub);
		testSignForm(dur, robot);
		testSignForm(dur, pres);
	}

	{
		std::cout << "\n--- fur test (1) ---\n";
		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robot("robot");
		PresidentialPardonForm	pres("pres");
		
		testSignForm(fur, shrub);
		testSignForm(fur, robot);
		testSignForm(fur, pres);
	}

	{
		std::cout << "\n=== Forms Test ===\n";
		std::cout << "\n--- Shrubbery test ---\n";
		ShrubberyCreationForm	a("a");
		ShrubberyCreationForm	b("b");
		ShrubberyCreationForm	c("c1");
		ShrubberyCreationForm	d("d#");
		testSignForm(fur, a);
		testSignForm(fur, b);
		testSignForm(fur, c);
		testSignForm(fur, d);

		std::cout << "\n--- Robot test ---\n";
		// Test a few times to see that it works (should be different each time)
		RobotomyRequestForm	r("r");
		RobotomyRequestForm	s("s");
		RobotomyRequestForm	t("t");
		RobotomyRequestForm	u("u");

		testSignForm(fur, r);
		testSignForm(fur, s);
		testSignForm(fur, t);
		testSignForm(fur, u);

		std::cout << "\n--- Presidential test ---\n";
		PresidentialPardonForm	z("z");
		PresidentialPardonForm	y("y");
		PresidentialPardonForm	x("x");
		PresidentialPardonForm	w("w");

		testSignForm(fur, z);
		testSignForm(fur, y);
		testSignForm(fur, x);
		testSignForm(fur, w);
	}

	{
		std::cout << "\n=== Polymorphism test ===\n";
		AForm *form[3];
		form[0] = new ShrubberyCreationForm("shrubbery");
		form[1] = new RobotomyRequestForm("robotomy");
		form[2] = new PresidentialPardonForm("president");

		for (int i = 0; i < 3; i++)
		{
			cur.signForm(*form[i]);
			cur.executeForm(*form[i]);
		}

		std::cout << "\n";
		for (int i = 0; i < 3; i++)
		{
			dur.signForm(*form[i]);
			dur.executeForm(*form[i]);
			delete form[i];
		}
	}
}

static void	testSignForm(Bureaucrat& b, AForm& f)
{
	b.signForm(f);
	b.executeForm(f);
}

/* static void testBureaucrat(std::string name, int grade)
{
	try
	{
		Bureaucrat	bureaucrat(name, grade);
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
} */

/* static void testForm(std::string name, int signgrade, int execgrade)
{
	try
	{
		Form form(name, signgrade, execgrade);
		std::cout << form << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
} */