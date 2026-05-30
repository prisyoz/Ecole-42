#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& original) : AAnimal(original)
{
	this->type = original.type;
	this->brain = new Brain(*original.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& original)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &original)
	{
		AAnimal::operator=(original);

		if (this->brain && original.brain)
			*this->brain = *original.brain;
		else if (original.brain)
			this->brain = new Brain(*original.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

Dog&	Dog::setDogIdea(unsigned int index, std::string idea)
{
	if (index >= 100)
		std::cout << "Dog got no space for ideas" << std::endl;
	else if (this->brain)
		this->brain->setIdeas(index, idea);
	else
		std::cout << "This dog got no brain" << std::endl;
	return (*this);
}

std::string	Dog::getIdea(unsigned int index) const
{
	if (index >= 100)
		return ("Cat dont have this idea number");
	else
		return (this->brain->getIdeas(index));
}
