#include "ClapTrap.hpp"

void	printDetails(ClapTrap& target);

int	main(void)
{	
	{
		std::cout << "\n===COPY CONSTRUCTOR TEST===\n";
		ClapTrap a("a");
		ClapTrap b("b");
		ClapTrap c(a);

		std::cout << "a: " << a.getName() << "\n";
		std::cout << "b: " << b.getName() << "\n";
		std::cout << "c: " << c.getName() << "\n";

		std::cout << "\n===ASSIGNMENT OPERATOR TEST===\n";
		ClapTrap d("d");
		std::cout << "d: " << d.getName() << "\n";
		d = b;
		std::cout << "d: " << d.getName() << std::endl;
	}

	{
		std::cout << "\n===CLAPTRAP TEST===\n";
		ClapTrap a("a");
		ClapTrap b("b");

		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Attack and Repair ---\n";
		
		a.attack("b");
		b.beRepaired(10);

		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Loop test ---\n";
		for (int i = 0; i < 11; i++)
			a.attack("b");

		for (int i = 0; i < 11; i++)
			b.beRepaired(10);
		
		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Death test ---\n";
		a.takeDamage(5);
		a.takeDamage(5);
		a.takeDamage(5);
		b.takeDamage(200);
		b.takeDamage(10);
		a.beRepaired(10);
		b.beRepaired(1);
		
		printDetails(a);
		printDetails(b);
	}

	
}

void	printDetails(ClapTrap& target)
{
	std::cout << target.getName() << ": " << target.getHitpts() << " HP | " << target.getEnergypts() << " EP | "
		<< target.getAttackdmg() << " dmg\n";
}