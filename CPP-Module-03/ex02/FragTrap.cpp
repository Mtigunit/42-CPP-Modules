#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
	std::cout << "FragTrap: Default constructor called." << std::endl;
}

FragTrap::FragTrap( FragTrap& Copy ) : ClapTrap(Copy) {
	std::cout << "FragTrap: Copy constructor called." << std::endl;
	*this = Copy;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	std::cout << "FragTrap " + name + " created." << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap: Destructor called." << std::endl;
}

FragTrap&	FragTrap::operator= (const FragTrap& src) {
	std::cout << "FragTrap: Assign operator called." << std::endl;
	this->Health = src.Health;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys( void ) {
	if (this->Health > 0)
		std::cout << "hey " + name + "! HightFive..." << std::endl;
	else
		std::cout << "hey " + name + " Are you still with me? No? so there is no HightFive :("  << std::endl;
}