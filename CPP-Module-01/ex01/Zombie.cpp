#include "Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout << Zombie::getName() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
        std::cout << "Destroying zombie: " << name << std::endl;
}

Zombie::Zombie( void ) {}

void	Zombie::setName( std::string name ) {
	this->name = name;
}

std::string	Zombie::getName( void ) {
	return (name);
}
