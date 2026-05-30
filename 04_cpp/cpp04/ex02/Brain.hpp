#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "AAnimal.hpp"

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain& original);
		Brain& operator=(const Brain& original);
		~Brain();

		void		setIdeas(unsigned int index, std::string idea);
		std::string	getIdeas(unsigned int index);
};

#endif