/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 23:56:48 by pang              #+#    #+#             */
/*   Updated: 2026/07/11 07:49:53 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	srand(time(NULL));

	std::cout << "test1\n";
	Base* test1 = generate();
	identify(test1);
	identify(*test1);

	std::cout << "test2\n";
	Base* test2 = generate();
	identify(test2);
	identify(*test2);

	std::cout << "test3\n";
	Base* test3 = generate();
	identify(test3);
	identify(*test3);

	// std::cout << "\n Invalid test\n";
	// std::cout << "test4\n";
	// Base* test4 = NULL;
	// identify(test4);
	// identify(*test4); 

	// delete test4;
	delete test3;
	delete test2;
	delete test1;
}

/* 	Ref doesn't run, coz ref doesn't exist on its own. 
	Needs to be bound to a memory, in this case, don't have.
	Hence, doesn't exist */