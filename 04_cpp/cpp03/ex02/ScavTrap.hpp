#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string const& name);
		ScavTrap(const ScavTrap& original);
		ScavTrap& operator=(const ScavTrap& original);
		~ScavTrap();

		void		guardGate();
		std::string	getType() const;
		void		attack(const std::string& target);
};

#endif