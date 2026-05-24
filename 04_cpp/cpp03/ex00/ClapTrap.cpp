#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& name) : _name(name), _hitpts(10), _energypts(10), _attackdmg(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& original) : _name(original._name), _hitpts(original._hitpts), _energypts(original._energypts), _attackdmg(original._attackdmg)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &original)
	{
		_name = original._name;
		_hitpts = original._hitpts;
		_energypts = original._energypts;
		_attackdmg = original._attackdmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int	ClapTrap::getHitpts() const
{
	return (this->_hitpts);
}

int	ClapTrap::getEnergypts() const
{
	return (this->_energypts);
}

int	ClapTrap::getAttackdmg() const
{
	return (this->_attackdmg);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energypts > 0 && _hitpts > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << _attackdmg << " points of damage!" << std::endl;
		_energypts--;
	}
	else if (_energypts == 0 && _hitpts > 0)
	{
		std::cout << "No attack. ClapTrap " << _name 
			<< " has no energy points left" << std::endl;
	}
	else
		std::cout << "No attack. ClapTrap " << _name << " is dead. Cannot attack" << std::endl;		
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpts == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead and cannot die again" << std::endl;
		return ;
	}
	
	if (_hitpts > amount)
	{
		_hitpts -= amount;
		std::cout << "ClapTrap " << _name << " has taken " 
			<< amount << " of damage and has " << _hitpts
			<< " HP left" << std::endl;
	}
	else
	{
		_hitpts = 0;
		std::cout << "ClapTrap " << _name << " has taken " 
			<< amount << " of damage and has " << _hitpts
			<< " HP left" << std::endl;
		std::cout << "ClapTrap " << _name << " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpts == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead, cannot be repaired" << std::endl;
		return ;
	}
	if (_energypts > 0 && _hitpts > 0)
	{
		_energypts--;
		_hitpts += amount;
		std::cout << "ClapTrap " << _name << " has been repaired for "
			<< amount << " HP. " << _name << " now has " << _hitpts << " HP" << std::endl;
	}
	else if (_energypts == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy pts left, cannot be repaired" << std::endl;
	}
}
