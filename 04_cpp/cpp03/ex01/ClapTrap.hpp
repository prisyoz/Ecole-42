#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitpts;
		unsigned int	_energypts;
		unsigned int	_attackdmg;

	public:
		ClapTrap(std::string const& name);
		ClapTrap(const ClapTrap& original);
		ClapTrap& operator=(const ClapTrap& original);
		virtual ~ClapTrap();

		std::string			getName() const;
		int					getHitpts() const;
		int					getEnergypts() const;
		int					getAttackdmg() const;
		virtual std::string	getType() const;
		
		virtual void		attack(const std::string& target);
		virtual void		takeDamage(unsigned int amount);
		virtual void		beRepaired(unsigned int amount);
};

#endif