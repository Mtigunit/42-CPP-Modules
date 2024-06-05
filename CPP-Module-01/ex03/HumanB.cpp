#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name), weapon(NULL) {
	std::cout << "A HumanB got constructed." << std::endl;
}

HumanB::~HumanB( void ) {
	std::cout << "HumanB: " << name << " destroyed." << std::endl;
}

std::string	HumanB::getName( void ) {
	return (this->name);
}

Weapon*	HumanB::getWeapon( void ) {
	return (this->weapon);
}

void	HumanB::setName( std::string name ) {
	this->name = name;
}

void	HumanB::setWeapon( Weapon weapon ) {
	this->weapon = &weapon;
}

void	HumanB::attack( void ) {
	if (this->weapon) {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << name << " is unarmed!" << std::endl;
	}
}
