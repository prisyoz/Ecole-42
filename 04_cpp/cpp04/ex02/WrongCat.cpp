#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& original) : WrongAnimal()
{
	this->type = original.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& original)
{
	if (this != &original)
		this->type = original.type;
	return (*this);
	std::cout << "WrongCat assignment operator called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meoof Meoof" << std::endl;
}


