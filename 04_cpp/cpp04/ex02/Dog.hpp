#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
{
	private:
		Brain	*brain;

	public:
		Dog();
		Dog(const Dog& original);
		Dog& operator=(const Dog& original);
		~Dog();

		void		makeSound() const;
		Dog&		setDogIdea(unsigned int index, std::string idea);
		std::string	getIdea(unsigned int index) const;
};

#endif