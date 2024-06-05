#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : name(name), weapon(weapon) {
	std::cout << "A HumanA got constructed." << std::endl;
}

HumanA::~HumanA( void ) {
	std::cout << "HumanA: " << name << " destroyed." << std::endl;
}

std::string	HumanA::getName( void ) {
	return (this->name);
}

Weapon&	HumanA::getWeapon( void ) {
	return (this->weapon);
}

void	HumanA::setName( std::string name ) {
	this->name = name;
}

void	HumanA::setWeapon( Weapon weapon ) {
	this->weapon = weapon;
}

void	HumanA::attack( void ) {
	std::cout << name << " attacks with their "
			  << this->weapon.getType() << std::endl;
}