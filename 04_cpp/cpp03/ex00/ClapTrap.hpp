#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitpts;
		unsigned int	_energypts;
		unsigned int	_attackdmg;

	public:
		ClapTrap(std::string const& name);
		ClapTrap(const ClapTrap& original);
		ClapTrap& operator=(const ClapTrap& original);
		~ClapTrap();

		std::string	getName() const;
		int			getHitpts() const;
		int			getEnergypts() const;
		int			getAttackdmg() const;
		
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif