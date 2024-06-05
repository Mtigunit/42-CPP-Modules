#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), Health(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& Copy) {
	std::cout << "Copy constructor called." << std::endl;
	*this = Copy;
}

ClapTrap::ClapTrap(std::string name) : name(name), Health(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " + name + " created." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called." << std::endl;
}

ClapTrap&	ClapTrap::operator= (ClapTrap& src) {
	std::cout << "Assignment operator called." << std::endl;
	this->name = src.name;
	this->Health = src.Health;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (Health == 0) {
		std::cout << "Attack failed! ClapTrap "<< name << " is died!" << std::endl;
		return ;
	}
	if (energyPoints > 0) {
		std::cout << "ClapTrap " + name + " attacks " << target
				<< ", causing " << attackDamage
				<< " of damage." << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " + name + " doesn't have enough energy points to attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (Health > 0) {
		Health = (Health > amount) ? Health - amount : 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " of damage.";
		std::cout << std::endl;
		if (Health == 0) {
			std::cout << "ClapTrap " << name << " died." << std::endl;
		}
	} else {
		std::cout << "TakeDamage failed! ClapTrap " << name << " is already died!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (Health == 0) {
		std::cout << "Repair failed! ClapTrap " << name << " is died!" << std::endl;
		return ;
	}
	if (energyPoints > 0) {
		Health += amount;
		std::cout << "ClapTrap " << name << " gains " << amount << " hit points.";
		std::cout << std::endl;
		energyPoints--;
	} else {
		std::cout << "Repair failed! ClapTrap " << name << " has no energy points!" << std::endl;
	}
}
