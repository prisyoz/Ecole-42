#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string		type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& original);
		WrongAnimal& operator=(const WrongAnimal& original);
		virtual ~WrongAnimal();

		void makeSound() const;
		std::string		getType() const;
};

#endif