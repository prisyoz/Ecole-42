#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
	this->type = original.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
	if (this != &original)
		this->type = original.type;
	return (*this);
	std::cout << "WrongAnimal assignment operator called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Wrong" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}