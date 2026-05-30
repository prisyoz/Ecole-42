#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "=== SUBJECT TEST===" << std::endl;
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

	{
		std::cout << "\n=== HOUSE ARRAY ===\n";
		const Animal	*house[3];

		house[0] = new Dog();
		house[1] = new Cat();
		house[2] = new Animal();

		for (int i = 0; i < 3; i++)
		{
			std::cout << "House " << i << " : " << house[i]->getType() << " \n";
			house[i]->makeSound();
		}

		for (int i = 0; i < 3; i++)
			delete house[i];

	}

	return 0;

} 