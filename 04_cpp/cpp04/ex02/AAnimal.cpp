#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "AAnimal";
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& original)
{
	this->type = original.type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& original)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &original)
		this->type = original.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

std::string AAnimal::getIdea(unsigned int index) const
{
	(void) index;
	return ("I am an AAnimal. I have no brains");
}
