/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:17:07 by pang              #+#    #+#             */
/*   Updated: 2026/07/01 16:17:08 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void testBureaucrat(std::string name, int grade);

int	main(void)
{
	{
		std::cout << "=== BASIC TEST ===\n";
		
		testBureaucrat("a", 60);
		testBureaucrat("b", 180);
		testBureaucrat("c", -5);
		testBureaucrat("d", 0);

 		try
		{
			Bureaucrat	ori("ori", 55);
			std::cout << "ori: " << ori << std::endl;

			Bureaucrat	clone(ori);
			std::cout << "clone: " << clone << std::endl;

			// copy constructor independent
			std::cout << "\n";
			ori.upGrade();
			std::cout << "ori: " << ori << std::endl;
			std::cout << "clone: " << clone << std::endl;

			// assign operator
			std::cout << "\n";
			Bureaucrat	assign("assign", 141);
			std::cout << "Before: " << assign << std::endl;

			assign = clone;
			std::cout << "After: " << assign << std::endl; // name should remain as assign
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n=== INCREASE DECREASE GRADE ===\n";
		try
		{
			Bureaucrat	f("f", 150);
			std::cout << f << std::endl;
			f.upGrade();
			std::cout << f << std::endl;
			f.downGrade();
			std::cout << f << std::endl;
			f.downGrade();
			std::cout << f << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Bureaucrat	g("g", 1);
			std::cout << g << std::endl;
			g.downGrade();
			std::cout << g << std::endl;
			g.upGrade();
			std::cout << g << std::endl;
			g.upGrade();
			std::cout << g << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

static void testBureaucrat(std::string name, int grade)
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
}