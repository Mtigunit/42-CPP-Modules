#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void ) {
	ScavTrap	Def;
	Def.attack("DefaultEnemy");
	Def.guardGate();
	Def.beRepaired(5);
	Def.takeDamage(1000);
	Def.guardGate();

	std::cout << "=====================\n";

	ScavTrap	Sp("Caty");
	Sp.attack("Enemy");
	Sp.beRepaired(5);
	Sp.takeDamage(10);
	Sp.guardGate();

	std::cout << "=====================\n";

	ScavTrap *test = new ScavTrap("Sp-heap");
	test->attack("heapEnemy");
	test->beRepaired(6);
	test->takeDamage(50);
	test->guardGate();
	delete test;
	return (0);
}
