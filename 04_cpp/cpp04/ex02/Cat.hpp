#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat& original);
		Cat& operator=(const Cat& original);
		~Cat();

		void		makeSound() const;
		Cat&		setCatIdea(unsigned int index, std::string idea);
		std::string	getIdea(unsigned int index) const;
};

#endif