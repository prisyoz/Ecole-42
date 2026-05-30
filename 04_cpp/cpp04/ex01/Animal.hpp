#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string type;
		
	public:
		Animal();
		Animal(const Animal& original);
		Animal& operator=(const Animal& original);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
		virtual std::string	getIdea(unsigned int index) const;
};

#endif