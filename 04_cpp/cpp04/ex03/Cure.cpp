#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& original) : AMateria(original)
{
	this->_type = original._type;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& original)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &original)
		AMateria::operator=(original);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	AMateria *a = new Cure(*this);
	return (a);
}

void	Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}