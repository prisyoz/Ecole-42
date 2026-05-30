#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

#include <iostream>
#include <string>

# define MAX_DROPPED 4

class Character : public ICharacter
{
	private:
		AMateria*	 _invent[4];
		std::string	_name;
		AMateria*	_dropped[MAX_DROPPED];
		int			_dropCount;

	public:
		Character();
		Character(std::string const name);
		Character(const Character& original);
		Character& operator=(const Character& original);
		~Character();

		virtual	std::string const &	getName() const;
		virtual	void		equip(AMateria* m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter& target);

		void				printInventory() const;
};

#endif