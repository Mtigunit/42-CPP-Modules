#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap	Default;
	Default.attack("DefaultEnemy");
	Default.beRepaired(5);
	Default.takeDamage(10);
	Default.takeDamage(100);

	std::cout << "================" << std::endl;

	ClapTrap	Cp("Spider");
	Cp.attack("Enemy");
	Cp.beRepaired(5);
	Cp.takeDamage(10);
	Cp.takeDamage(100);
	return (0);
}
