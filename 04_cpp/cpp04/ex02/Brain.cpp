#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& original)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = original.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& original)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &original)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = original.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdeas(unsigned int index, std::string idea)
{
	if (index >= 100)
	{
		std::cout << "Not enough space for ideas" << std::endl;
		return ;
	}
	else
		this->ideas[index] = idea;
}

std::string	Brain::getIdeas(unsigned int index)
{
	if (index >= 100)
	{
		std::cout << "No such ideas" << std::endl;
		return "";
	}
	else
		return (this->ideas[index]);
}
