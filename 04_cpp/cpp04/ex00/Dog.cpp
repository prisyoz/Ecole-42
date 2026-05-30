#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& original) : Animal(original)
{
	this->type = original.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& original)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &original)
		this->type = original.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
