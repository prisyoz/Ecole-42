#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitpts = FragTrap::_hitpts;
	this->_energypts = ScavTrap::_energypts;
	this->_attackdmg = FragTrap::_attackdmg;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& original) : ClapTrap(original), ScavTrap(original), FragTrap(original)
{
	this->_name = original._name;
	this->_hitpts = original._hitpts;
	this->_energypts = original._energypts;
	this->_attackdmg = original._attackdmg;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& original)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &original)
	{
		ClapTrap::operator=(original);
		this->_name = original._name;
		this->_hitpts = original._hitpts;
		this->_energypts = original._energypts;
		this->_attackdmg = original._attackdmg;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

std::string DiamondTrap::getType() const
{
	return ("DiamondTrap");
}

std::string	DiamondTrap::getName() const
{
	return (this->_name);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmi(void)
{
	if (_hitpts > 0)
		std::cout << "I am " << this->getName() << " and my ClapTrap name is "
			<< ClapTrap::_name << std::endl;
	else
		std::cout << "Sorry, your DiamondTrap " << this->getName() << " is dead" << std::endl;
}
