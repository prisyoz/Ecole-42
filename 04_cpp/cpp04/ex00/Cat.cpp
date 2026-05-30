#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& original) : Animal(original)
{
	this->type = original.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& original)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &original)
		this->type = original.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}