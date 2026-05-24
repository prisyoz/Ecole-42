#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name)
{
	_energypts = 50;
	_hitpts = 100;
	_attackdmg = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original._name)
{
	_energypts = original._energypts;
	_hitpts = original._hitpts;
	_attackdmg = original._attackdmg;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& original)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &original)
	{
		_name = original._name;
		_energypts = original._energypts;
		_hitpts = original._hitpts;
		_attackdmg = original._attackdmg;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (_hitpts > 0)
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is already dead and cannot guard gate" << std::endl;
}

std::string	ScavTrap::getType() const
{
	return ("ScavTrap");
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energypts > 0 && _hitpts > 0)
	{
		std::cout << this->getType() << " " << _name << " attacks " << target
			<< ", causing " << _attackdmg << " points of damage!" << std::endl;
		_energypts--;
	}
	else if (_energypts == 0 && _hitpts > 0)
	{
		std::cout << "No attack. " << this->getType() << " " << _name 
			<< " has no energy points left" << std::endl;
	}
	else
		std::cout << "No attack. " << this->getType() << " " << _name << " is dead. Cannot attack" << std::endl;		
}
