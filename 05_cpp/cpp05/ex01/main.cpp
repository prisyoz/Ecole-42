/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:17:31 by pang              #+#    #+#             */
/*   Updated: 2026/07/01 16:17:31 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// static void testBureaucrat(std::string name, int grade);
static void testForm(std::string name, int signgrade, int execgrade);

int	main(void)
{
	{
		std::cout << "=== BASIC TEST ===\n";
		
		testForm("a", 60, 60);
		testForm("b", 180, 60);
		testForm("c", 60, 180);
		testForm("d", -5, 60);
		testForm("e", 60, -5);

		std::cout << "\n";

		try
		{
			Bureaucrat b("b", 45);

			Form	ori("ori", 55, 60);
			std::cout << "ori: " << ori << std::endl;

			Form	clone(ori);
			std::cout << "clone: " << clone << std::endl;

			// sign copy constructor form for independency
			std::cout << "\n";
			clone.beSigned(b);
			std::cout << "ori: " << ori << std::endl;
			std::cout << "clone: " << clone << std::endl;

			std::cout << "\n";
			Form	assign("assign", 141, 1);
			std::cout << "Before assign: " << assign << std::endl;

			// assignment operator (clone should be signed but form shouldn't change)
			assign = clone;
			std::cout << "clone: " << clone << std::endl;
			std::cout << "After assign: " << assign << std::endl;

			std::cout << "\n";
			assign = assign;
			std::cout << "Self-assign: " << assign << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n=== Grade Test ===\n";

		Form a("a", 60, 60);
		Form b("b", 59, 60);
		Form c("c", 60, 59);
		Form d("d", 150, 1);
		Form e("e", 1, 150);

		Bureaucrat bur("bur", 60);
		Bureaucrat cur("cur", 59);
		Bureaucrat dur("dur", 61);
		Bureaucrat fur("fur", 1);
		Bureaucrat gur("gur", 150);

		std::cout << bur << "\n";
		bur.signForm(a);
		bur.signForm(b);
		bur.signForm(c);
		bur.signForm(d);
		bur.signForm(e);

		std::cout << "\n" << dur << "\n";
		dur.signForm(a);
		dur.signForm(b);
		dur.signForm(c);
		dur.signForm(d);
		dur.signForm(e);

		std::cout << "\n" << fur << "\n";
		fur.signForm(a);
		fur.signForm(b);
		fur.signForm(c);
		fur.signForm(d);
		fur.signForm(e);

		std::cout << "\n" << gur << "\n";
		gur.signForm(a);
		gur.signForm(b);
		gur.signForm(c);
		gur.signForm(d);
		gur.signForm(e);	

		std::cout << "\n--- Resign a form flipped---\n";
		Bureaucrat	hur("hur", 1);
		Form		f("f", 49, 42);
		std::cout << "Before: " << f << std::endl;
		hur.signForm(f);
		std::cout << "After1: " << f << std::endl;
		hur.signForm(f);
		std::cout << "After2: " << f << std::endl;

		std::cout << "\n --- Up and Down grade ---\n";
		std::cout << dur << "\n";
		dur.signForm(a);
		dur.signForm(b);
		dur.signForm(c);
		dur.signForm(d);
		dur.signForm(e);

		dur.upGrade();
		std::cout << "\nUpGrade: " << dur << "\n";
		dur.signForm(a);
		dur.signForm(b);
		dur.signForm(c);
		dur.signForm(d);
		dur.signForm(e);


		std::cout << "\n";
		std::cout << cur << "\n";
		cur.signForm(a);
		cur.signForm(b);
		cur.signForm(c);
		cur.signForm(d);
		cur.signForm(e);

		cur.downGrade();
		std::cout << "\nDownGrade: " << cur << "\n";
		cur.signForm(a);
		cur.signForm(b);
		cur.signForm(c);
		cur.signForm(d);
		cur.signForm(e);
	}
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

static void testForm(std::string name, int signgrade, int execgrade)
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
}