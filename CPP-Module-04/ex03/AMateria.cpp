#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << "AMateria " << type << " got constructed." << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called." << std::endl;
}

std::string const&	AMateria::getType() const {
	return (this->type);
}

AMateria::AMateria(const AMateria& Copy) {
	this->type = Copy.getType();
}

void	AMateria::use(ICharacter& target) {
	std::cout << "Using materia on character: " << target.getName() << std::endl;
}
