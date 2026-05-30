#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <sstream>

int	main(void)
{
	std::cout << "=== NEW TESTS===\n";
	{
		std::cout << "\n=== BRAIN TEST===\n";
		Dog *a = new Dog();
		Cat *b = new Cat();
		Cat *c = new Cat();
		Cat *d = new Cat();

		std::cout << "\n";

		// set ideas
		a->setDogIdea(0, "Test test");
		a->setDogIdea(1, "Test cat");
		a->setDogIdea(200, "Idea 200"); // print out Dog no space for idea
		b->setCatIdea(10, "A test for cat").setCatIdea(11, "Idea 11").setCatIdea(0, "A try");
		d->setCatIdea(0, "Idea d");

		// Print out Cat no space for idea
		for (int i = 0; i < 101; i++)
		{
			std::stringstream ss;
			ss << "Test " << i;
			c->setCatIdea(i, ss.str());
		}

		std::cout << a->getIdea(0) << std::endl;
		std::cout << b->getIdea(11) << std::endl;
		std::cout << c->getIdea(99) << std::endl;
		std::cout << c->getIdea(100) << std::endl;
		std::cout << d->getIdea(0) << std::endl;

		*d = *b;
		std::cout << d->getIdea(11) << std::endl;
		std::cout << d->getIdea(0) << std::endl;
		std::cout << "\n";

		delete d;
		delete c;
		delete b;
		delete a;

	}

	{
		std::cout << "\n=== HOUSE ARRAY IDEAS ===\n";
		const Animal	*house[4];

		Dog	*Dog1 = new Dog();
		Dog1->setDogIdea(0, "I am a dog");
		Dog	*Dog2 = new Dog();
		Dog2->setDogIdea(0, "Yeah, he's a dog");
		Cat *Cat1 = new Cat();
		Cat1->setCatIdea(0, "I am a cat");
		Cat	*Cat2 = new Cat();
		Cat2->setCatIdea(0, "He ain't a dog");

		house[0] = Dog1;
		house[1] = Cat1;
		house[2] = Dog2;
		house[3] = Cat2;

		std::cout << "\n";
		for (int i = 0; i < 4; i++)
		{
			std::cout << "House " << i << " : " << house[i]->getType() << " \n";
			std::cout << house[i]->getIdea(0) << "\n";
			house[i]->makeSound();
		}
		std::cout << "\n";

		for (int i = 0; i < 4; i++)
			delete house[i];
	}

	{
		std::cout << "\n=== OLD TESTS===" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
		Animal	a;
		Animal	b(a);
		Dog		c;
		Cat		d;

		a.makeSound();
		b.makeSound();
		c.makeSound();
		d.makeSound();

		std::cout << "=== Assignment operator test ===\n";
		std::cout << "a: " << a.getType() << std::endl;
		std::cout << "c: " << c.getType() << std::endl;
		a = c;
		std::cout << "a: " << a.getType() << std::endl;
		std::cout << "c: " << c.getType() << std::endl;
		a.makeSound();
		c.makeSound();
	}

	{
		std::cout << "\n=== WRONG CAT ===\n";
		WrongAnimal	a;
		WrongAnimal	b(a);
		WrongCat	c;
		
		std::cout << "a: " << a.getType() << std::endl;
		std::cout << "b: " << b.getType() << std::endl;
		std::cout << "c: " << c.getType() << std::endl;
		a.makeSound();
		b.makeSound();
		c.makeSound();
	}

	return 0;
}