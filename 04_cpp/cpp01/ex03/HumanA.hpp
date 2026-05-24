#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

#include <iostream>

// have weapon and a name
class   HumanA
{
    private:
        std::string _name;
        Weapon&		_weapon; // ref

    public:
        HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack() const;
};

#endif