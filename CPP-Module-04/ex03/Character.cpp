#include "Character.hpp"
#include <iostream>

// Character::Character() : name("") {
// 	std::cout << "Character constructor called." << std::endl;
// }

Character::Character( const std::string name ) : name(name) {
	std::cout << name << " got constructed." <<  std::endl;
	for (size_t i = 0; i < 4; i++) {
		Inventory[i] = nullptr;
	}
}

Character::Character( const Character& Copy) {
	std::cout << "Character copy constructor called." << std::endl;
	*this = Copy;
}

Character::~Character() {
	for (size_t i = 0; i < 4; i++) {
		if (Inventory[i]) {
			delete Inventory[i];
		}
	}
	std::cout << name << " has been destroyed." << std::endl;
}

Character&	Character::operator=( const Character& src) {
	std::cout << name << ": assignement operator called." << std::endl;
	if (this != &src) {
		name = src.name;
		for (int i = 0; i < 4; i++) {
			if (Inventory[i]) {
				delete Inventory[i];
			}
			Inventory[i] = nullptr;
			if (src.Inventory[i])
			{
				Inventory[i] = src.Inventory[i]->clone();
			}
		}
	}
	return (*this);
}

std::string const& Character::getName() const {
	return (name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Nothing means nothing... <nullPtr>" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++) {
		if (m == Inventory[i]) {
			std::cout << "This materia is already equipped!" << std::endl;
			return ;
		}
	}
	for (size_t i = 0; i < 4; i++) {
		if (Inventory[i] == nullptr) {
			Inventory[i] = m;
			std::cout << name << " equiped materia " << m->getType() << " in slot " << i << "." << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full. Cannot equip " << m->getType() << "." << std::endl;
	delete m;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Another nothing means nothing haha... <outOfRange>" << std::endl;
		return ;
	}
	AMateria* tmp = Inventory[idx];
	std::cout << tmp->getType() << " uniquipped at slot " << idx << std::endl;
	Inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || Inventory[idx] == nullptr) {
		std::cout << "Again nothing means nothing... <outOfRange> | <nullPtr>" << std::endl;
		return;
	}
	Inventory[idx]->use(target);
}
