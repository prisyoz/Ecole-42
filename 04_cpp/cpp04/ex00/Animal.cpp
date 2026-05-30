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