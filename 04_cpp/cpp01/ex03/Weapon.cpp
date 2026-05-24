#include "Weapon.hpp"

const std::string&	Weapon::getType() const
{
    return this->_type;
}

void    Weapon::setType(std::string newType)
{
	_type = newType;
}

Weapon::~Weapon()
{

}

Weapon::Weapon(std::string type) : _type(type)
{

}