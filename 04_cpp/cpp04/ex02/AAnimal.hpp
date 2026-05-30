#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class	AAnimal
{
	protected:
		std::string type;
		
	public:
		AAnimal();
		AAnimal(const AAnimal& original);
		AAnimal& operator=(const AAnimal& original);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;
		virtual std::string	getIdea(unsigned int index) const;
};

#endif