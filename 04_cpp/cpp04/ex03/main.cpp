/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:27:23 by pang              #+#    #+#             */
/*   Updated: 2026/05/19 21:55:27 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main(void)
{
	{
		std::cout << "=== Basic Test ===\n";
		AMateria *a = new Cure();
		AMateria *b = new Ice();
		Cure c;
		Cure d;

		std::cout << "\n";
		std::cout << "a: " << a->getType() << std::endl;
		std::cout << "b: " << b->getType() << std::endl;
		std::cout << "\n";

		c = d;
		std::cout << "c: " << c.getType() << std::endl;
		std::cout << "\n";

		AMateria *e;
		AMateria *f = b->clone();
		e = a->clone();
		std::cout << "e: " << e->getType() << std::endl;
		std::cout << "f: " << f->getType() << std::endl;
		std::cout << "\n";

		delete f;
		delete e;
		delete b;
		delete a;
	}

	{
		std::cout << "\n=== CHARACTER TEST ===\n" << std::endl;

		Character mafia("Mafia");
		AMateria *a = new Cure();
		AMateria *b = new Ice();
		AMateria *c = new Cure();
		AMateria *d = new Ice();

		std::cout << "\n--- Equip Character inventory ---\n";
		mafia.equip(a->clone());
		mafia.equip(b->clone());
		mafia.equip(c->clone());
		mafia.equip(d->clone());

		mafia.printInventory();

		std::cout << "\n--- Inventory copy constructor test ---\n";
		Character opfia(mafia);
		std::cout << opfia.getName() << std::endl;
		opfia.printInventory();

		std::cout << "\n--- Inventory assignment operator test ---\n";
		Character wefia("wefia");
		std::cout << "wefia: " << wefia.getName() << std::endl;
		wefia.printInventory();
		std::cout << "\nWEFIA ASSIGN TO OPFIA\n";
		wefia = opfia;
		std::cout << "wefia name: " << wefia.getName() << std::endl;
		wefia.printInventory();

		std::cout << "\n--- Use attack function ---\n";
		Character victim("Victim");
		mafia.use(0, opfia); // Cure
		mafia.use(1, wefia); // Ice
		mafia.use(2, victim); // Cure
		mafia.use(3, victim); // Ice
		mafia.use(4, victim); //inexistent
		std::cout << "\n";

		std::cout << "\n--- Equip Unequip test ---\n";
		std::cout << "EQUIP INTO FULL INVENTORY\n";
		wefia.equip(c->clone());
		wefia.printInventory();

		std::cout << "\nUNEQUIP INDEX 2\n";
		wefia.unequip(2);
		wefia.use(2, victim);
		wefia.printInventory();


		std::cout << "\nEQUIP AMATERIA D INTO 3/4 FULL INVENTORY" << std::endl;
		wefia.equip(d->clone());
		wefia.printInventory();
		std::cout << "\n" << std::endl;

		std::cout << "\nUNEQUIP EVERYTHING INTO DROPPED ARRAY\n" << std::endl;
		wefia.unequip(0);
		wefia.unequip(1);
		wefia.unequip(2);
		wefia.unequip(3);
		wefia.printInventory();

		delete d;
		delete c;
		delete b;
		delete a;
	}

	{
		std::cout << "\n=== MATERIA SOURCE TEST ===\n";

		MateriaSource src;

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.printMateria();

		std::cout << "\n";
		AMateria* m1 = src.createMateria("ice");
		AMateria* m2 = src.createMateria("cure");
		
		std::cout << "\n--- Unknown type ---\n";
		AMateria* m3 = src.createMateria("fire"); // unknown, returns 0
		if (!m3)
			std::cout << "fire: unknown materia, returned 0" << std::endl;

		std::cout << "m1: " << m1 << "\n";
		std::cout << "m2: " << m2 << "\n";
		std::cout << "m3: " << m3 << "\n" << std::endl;

		// equip and use
		std::cout << "\n--- Equip and use ---\n";
		Character lafia("Lafia");
		Character target("Target");

		lafia.equip(m1);
		lafia.equip(m2);
		lafia.use(0, target); // ice
		lafia.use(1, target); // cure
		lafia.use(2, target); // empty, nothing happens
		lafia.printInventory();
		
		std::cout << "\n--- Unequip test ---\n";
		lafia.unequip(1);
		lafia.use(1, target); // cure
		lafia.printInventory();

		// full source, try to learn a 5th
		std::cout << "\n--- Full source ---\n";
		src.learnMateria(new Ice());
		src.printMateria();

		std::cout << "\n--- Create Materia checks ---\n";
		MateriaSource dst;

		dst.learnMateria(new Ice());
		dst.learnMateria(new Ice());
		dst.learnMateria(new Ice());
		dst.learnMateria(new Ice());
		dst.printMateria();

		// When materia doesn't exist in learnMateria
		AMateria* a = dst.createMateria("cure"); // should return 0
		if (!a)
			std::cout << "cure: not learned, returned 0" << std::endl;
		else
		{
			std::cout << "Cure found in src" << std::endl;
			delete a;
		}
		std::cout << "a: " << a << std::endl;

		std::cout << "\nMATERIA EXIST\n";
		src.printMateria();
		AMateria* b = src.createMateria("cure");
		if (!b)
			std::cout << "cure: not learned, returned 0" << std::endl;
		else
		{
			std::cout << "Cure found in src" << std::endl;
			delete b;
		}
		std::cout << "b: " << b << std::endl;

		std::cout << "\n\n" << std::endl;
	}

	return 0;
}