/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:24:45 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:24:46 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& original) : Animal(original)
{
	this->type = original.type;
	this->brain = new Brain(*original.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& original)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &original)
	{
		this->type = original.type;

		if (this->brain && original.brain)
			*this->brain = *original.brain;
		else if (original.brain)
			this->brain = new Brain(*original.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

Cat&	Cat::setCatIdea(unsigned int index, std::string idea)
{
	if (index >= 100)
		std::cout << "Cat got no space for ideas" << std::endl;
	else if (this->brain)
		this->brain->setIdeas(index, idea);
	else
		std::cout << "This cat got no brain" << std::endl;
	return (*this);
}

std::string	Cat::getIdea(unsigned int index) const
{
	if (index >= 100)
		return ("Cat dont have this idea number");
	else
		return (this->brain->getIdeas(index));
}