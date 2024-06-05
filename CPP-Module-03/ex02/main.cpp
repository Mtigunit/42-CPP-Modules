#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {
	FragTrap	DefaultFragTrap;
	DefaultFragTrap.attack("FlagTrapDefaultEnemy");
	DefaultFragTrap.beRepaired(13);
	DefaultFragTrap.takeDamage(1337);
	DefaultFragTrap.highFivesGuys();

	std::cout << "\n=====================\n\n";

	FragTrap	fragTrap;
	fragTrap.attack("FlagTrapEnemy");
	fragTrap.beRepaired(13);
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(1337);

	std::cout << "\n=====================\n\n";
	
	ScavTrap	DefaultScavTrap;
	DefaultScavTrap.attack("ScavTravDefaultEnamy");
	DefaultScavTrap.beRepaired(13);
	DefaultScavTrap.takeDamage(1337);
	DefaultScavTrap.guardGate();

	std::cout << "\n=====================\n\n";

	ScavTrap scavTrap;
	scavTrap.attack("ScavTrapEnemy");
	scavTrap.beRepaired(13);
	scavTrap.guardGate();
	scavTrap.takeDamage(1337);

	std::cout << "\n=====================\n\n";

	ClapTrap	Default;
	Default.attack("ClapTrapDefaultEnemy");
	Default.beRepaired(5);
	Default.takeDamage(10);

	std::cout << "\n=====================\n\n";

	ClapTrap	Cp("Spider");
	Cp.attack("Enemy");
	Cp.beRepaired(5);
	Cp.takeDamage(10);

	std::cout << "\n=====================\n\n";
	return (0);
}
