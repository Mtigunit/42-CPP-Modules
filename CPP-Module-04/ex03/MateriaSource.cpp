#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	std::cout << "MateriaSourse constructor called." << std::endl;
	for (size_t i = 0; i < 4; i++) {
		msInventory[i] = nullptr;
	}
}

MateriaSource::MateriaSource( const MateriaSource& Copy ) {
	std::cout << "MateriaSourse copy constructor called." << std::endl;
	*this = Copy;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& src) {
	std::cout << "MateriaSourse assignement operator called." << std::endl;
	if (this != &src) {
		for (size_t i = 0; i < 4; i++) {
			if (msInventory[i]) {
				delete this->msInventory[i];
			}
			this->msInventory[i] = nullptr;
			if (src.msInventory[i]) {
				msInventory[i] = src.msInventory[i]->clone();
			}
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (msInventory[i]) {
			delete msInventory[i];
		}
	}
	std::cout << "MateriaSourse has been destroyed." << std::endl;
}

void	MateriaSource::learnMateria(AMateria* materia) {
	if (!materia) {
		std::cout << "Nothing to learn... <nullPtr>" << std::endl;
	}
	for (size_t i = 0; i < 4; i++) {
		if (msInventory[i] == nullptr) {
			msInventory[i] = materia;
			std::cout << "Materia " << materia->getType() << " learned\n";
			return ;
		}
	}
	std::cout << "No available slot to learn the materia." << std::endl;
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < 4; i++) {
		if (msInventory[i] != nullptr && msInventory[i]->getType() == type) {
			std::cout << type << " created." << std::endl;
			return (msInventory[i]->clone());
		}
	}
	std::cout << type << " not found." << std::endl;
	return (nullptr);
}
