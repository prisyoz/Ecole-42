/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:24:20 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:24:21 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& original)
{
	this->type = original.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& original)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &original)
		this->type = original.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "makes no sound." << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

std::string Animal::getIdea(unsigned int index) const
{
	(void) index;
	return ("I am an animal. I have no brains");
}
