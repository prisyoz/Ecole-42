#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

static void	printDetails(ClapTrap& target);
static void	launchAttack(ClapTrap& attacker, ClapTrap& target);

int	main(void)
{	
 	{
		std::cout << "\n===COPY CONSTRUCTOR TEST===\n";
		DiamondTrap a("a");
		DiamondTrap b("b");
		DiamondTrap c(a);

		std::cout << "a: " << a.getName() << "\n";
		std::cout << "b: " << b.getName() << "\n";
		std::cout << "c: " << c.getName() << "\n";

		std::cout << "\n===ASSIGNMENT OPERATOR TEST===\n";
		DiamondTrap d("d");
		std::cout << "d: " << d.getName() << "\n";
		d.takeDamage(20);
		printDetails(d);
		d = b;
		std::cout << "d: " << d.getName() << std::endl;
		printDetails(d);
		std::cout << "\n" << std::endl;
	}

	{
		std::cout << "\n===DIAMONDTRAP TEST===\n";
		DiamondTrap a("a");
		DiamondTrap b("b");

		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Attack and Repair ---\n";
		
		a.attack("b");
		b.takeDamage(a.getAttackdmg());
		b.beRepaired(10);
		a.whoAmi();
		b.whoAmi();

		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Loop test ---\n";
		for (int i = 0; i < 101; i++)
			a.attack("b");

		for (int i = 0; i < 101; i++)
			b.beRepaired(10);
		
		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Death test ---\n";
		a.takeDamage(50);
		a.takeDamage(50);
		a.beRepaired(10);
		a.takeDamage(20);
		b.takeDamage(200);
		b.beRepaired(1);
		
		printDetails(a);
		printDetails(b);

		std::cout << "\n--- whoAmi test ---\n";
		a.whoAmi();
		b.whoAmi();
		std::cout << "\n" << std::endl;
	}

	{
		std::cout << "\n=== DIAMONDTRAP FRAGTRAP CLAPTRAP SCAVTRAP ATTACK ===\n";
		ScavTrap a("a");
		ClapTrap b("b");
		FragTrap c("c");
		DiamondTrap d("d");

		std::cout << "\n";
		printDetails(a);
		printDetails(b);
		printDetails(c);
		printDetails(d);

		std::cout << "\n";
		launchAttack(b, c);
		launchAttack(c, d);
		launchAttack(d, a);
		launchAttack(a, b);
		launchAttack(b, c);
		launchAttack(c, d);
		c.highFiveGuys();
		a.guardGate();
		d.whoAmi();
		std::cout << "\n";
	}

	/* std::cout << "\n\n OLD TESTS\n";
	{
		std::cout << "\n===FRAGTRAP TEST===\n";
		FragTrap a("a");
		FragTrap b("b");

		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Attack and Repair ---\n";
		
		a.attack("b");
		b.takeDamage(a.getAttackdmg());
		b.beRepaired(10);
		a.highFiveGuys();
		b.highFiveGuys();

		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Loop test ---\n";
		for (int i = 0; i < 101; i++)
			a.attack("b");

		for (int i = 0; i < 101; i++)
			b.beRepaired(10);
		
		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Death test ---\n";
		a.takeDamage(50);
		a.takeDamage(50);
		a.beRepaired(10);
		a.takeDamage(20);
		b.takeDamage(200);
		b.beRepaired(1);
		
		printDetails(a);
		printDetails(b);

		std::cout << "\n--- HighFive test ---\n";
		a.highFiveGuys();
		b.highFiveGuys();
		std::cout << "\n" << std::endl;
	}

	{
		std::cout << "\n=== FRAGTRAP CLAPTRAP SCAVTRAP ATTACK ===\n";
		ScavTrap a("a");
		ClapTrap b("b");
		FragTrap c("c");

		std::cout << "\n";
		printDetails(a);
		printDetails(b);
		printDetails(c);

		std::cout << "\n";
		launchAttack(b, a);
		launchAttack(a, c);
		launchAttack(c, a);
		launchAttack(a, b);
		launchAttack(b, c);
		c.highFiveGuys();
		a.guardGate();
		std::cout << "\n";
	}

	{
		std::cout << "\n===SCAVTRAP TEST===\n";
		ScavTrap a("a");
		ScavTrap b("b");

		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Attack and Repair ---\n";
		
		a.attack("b");
		b.takeDamage(a.getAttackdmg());
		b.beRepaired(10);
		a.guardGate();
		b.guardGate();

		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Loop test ---\n";
		for (int i = 0; i < 51; i++)
			a.attack("b");

		for (int i = 0; i < 51; i++)
			b.beRepaired(10);
		
		printDetails(a);
		printDetails(b);

		std::cout << "\n--- Death test ---\n";
		a.takeDamage(50);
		a.takeDamage(50);
		a.beRepaired(10);
		a.takeDamage(20);
		b.takeDamage(200);
		b.beRepaired(1);
		
		printDetails(a);
		printDetails(b);

		std::cout << "\n--- GuardGate test ---\n";
		a.guardGate();
		b.guardGate();
	} 

	{
		std::cout << "\n=== SCAVTRAP VS CLAPTRAP ===\n";
		ScavTrap a("a");
		ClapTrap b("b");

		printDetails(a);
		printDetails(b);

		launchAttack(b, a);
		launchAttack(a, b);
		launchAttack(b, a);
		launchAttack(a, b);
	} */
	
}

static void	printDetails(ClapTrap& target)
{
	std::cout << target.getName() << ": " << target.getHitpts() << " HP | " << target.getEnergypts() << " EP | "
		<< target.getAttackdmg() << " dmg | type: " << target.getType() << "\n";
}

static void	launchAttack(ClapTrap& attacker, ClapTrap& target)
{
	attacker.attack(target.getName());
	if (target.getHitpts() <= 0)
	{
		std::cout << "Your target dead already, how to take damage" << std::endl;
		return ;
	}
	if (attacker.getHitpts() > 0)
		target.takeDamage(attacker.getAttackdmg());
}