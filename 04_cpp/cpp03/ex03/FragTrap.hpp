#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string const& name);
		FragTrap(const FragTrap& original);
		FragTrap& operator=(const FragTrap& original);
		~FragTrap();

		std::string		getType() const;
		virtual void	attack(const std::string& target);
		void			highFiveGuys(void);
};

#endif