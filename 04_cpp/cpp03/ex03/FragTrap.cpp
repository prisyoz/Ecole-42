#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{
	_hitpts = 100;
	_energypts = 100;
	_attackdmg = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original._name)
{
	this->_hitpts = original._hitpts;
	this->_energypts = original._energypts;
	this->_attackdmg = original._attackdmg;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& original)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &original)
	{
		this->_name = original._name;
		this->_hitpts = original._hitpts;
		this->_energypts = original._energypts;
		this->_attackdmg = original._attackdmg;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

std::string	FragTrap::getType() const
{
	return ("FragTrap");
}

void	FragTrap::attack(const std::string& target)
{
	if (_energypts > 0 && _hitpts > 0)
	{
		std::cout << this->getType() << " " << this->getName() << " attacks " << target
			<< ", causing " << _attackdmg << " points of damage!" << std::endl;
		_energypts--;
	}
	else if (_energypts == 0 && _hitpts > 0)
	{
		std::cout << "No attack. " << this->getType() << " " << this->getName() 
			<< " has no energy points left" << std::endl;
	}
	else
		std::cout << "No attack. " << this->getType() << " " << this->getName() << " is dead. Cannot attack" << std::endl;		
}

void	FragTrap::highFiveGuys(void)
{
	if (_hitpts <= 0)
		std::cout << "FragTrap " << this->getName() << " is already dead. High five yourself" << std::endl;
	else
		std::cout << "FragTrap " << this->getName() << " gives you a high five!" << std::endl;
}