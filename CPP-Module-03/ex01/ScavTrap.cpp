#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	std::cout << "ScavTrap: Default constructor called." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap& Copy ) : ClapTrap( Copy ) {
	std::cout << "ScavTrap: Copy constructor called." << std::endl;
	*this = Copy;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
	std::cout << "ScavTrap " + name + " created." << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap: Destructor called." << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& src) {
	std::cout << "ScavTrap: Assignement operator called." << std::endl;
	this->Health = src.Health;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return (*this);
}

void ScavTrap::guardGate() {
	if (Health == 0) {
		std::cout << "ScavTrap " + name + " cannot guard Gate! " + name + " is died.";
		std::cout << std::endl;
	} else {
		std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
	}
}

void	ScavTrap::attack(const std::string& target) {
	if (Health == 0) {
		std::cout << "Attack failed! ScavTrap "<< name << " is died!" << std::endl;
		return ;
	}
	if (energyPoints > 0) {
		std::cout << "ScavTrap " + name + " attacks " << target
				<< ", causing " << attackDamage
				<< " of damage." << std::endl;
		energyPoints--;
	} else {
		std::cout << "ScavTrap " + name + " doesn't have enough energy points to attack!" << std::endl;
	}
}
