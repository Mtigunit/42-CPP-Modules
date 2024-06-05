#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called." << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called." << std::endl;
}

Ice::Ice( const Ice& Copy) {
	std::cout << "Ice copy constructor called." << std::endl;
	*this = Copy;
}

Ice&	Ice::operator=( const Ice& src) {
	std::cout << "Assigned from " << src.getType() << std::endl;
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
