#include "Weapon.hpp"

Weapon::Weapon( std::string type ) {
	setType(type);
	std::cout << "Weapon got constructed!" << std::endl;
}

Weapon::~Weapon( void ) {
	std::cout << "Weapon " << getType() << " destroyed!" << std::endl;
}

const std::string&	Weapon::getType( void ) {
	return (type);
}

void	Weapon::setType( const std::string type ) {
	this->type = type;
}
