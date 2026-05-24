#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& original);
		DiamondTrap& operator=(const DiamondTrap& original);
		~DiamondTrap();

		std::string	getType() const;
		std::string	getName() const;
		void		attack(const std::string& target);
		void		whoAmi(void);
};

#endif
