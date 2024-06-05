#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor called." << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called." << std::endl;
}

Cure::Cure( const Cure& Copy) {
	std::cout << "Cure copy constructor called." << std::endl;
	*this = Copy;
}

Cure&	Cure::operator=( const Cure& src) {
	std::cout << "Assigned from " << src.getType() << std::endl;
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {	
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
