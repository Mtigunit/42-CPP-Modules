#include "Zombie.hpp"

Zombie::Zombie( const std::string zombieName ) {
	name = zombieName;
	std::cout << "Zombie: " << name << " got constructed." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Destroying zombie: " << name << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << Zombie::getName() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name ) {
	this->name = name;
}

std::string	Zombie::getName( void ) {
	return (name);
}
