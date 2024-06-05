#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void func() {
	system("leaks program");
}

void	MyTest( void ) {
	ICharacter* mainCharacter = new Character("superHero");
	ICharacter* enemy = new Character("Spider");
	IMateriaSource* ms = new MateriaSource;
	AMateria* ice1 = new Ice;
	AMateria* ice2 = new Ice;
	AMateria* cure1 = new Cure;
	AMateria* cure2 = new Cure;

	// equip
	mainCharacter->equip(ice1); // Ice default constructor
	mainCharacter->equip(ice2); // Ice default constructor
	mainCharacter->equip(cure1); // Cure default constructor
	mainCharacter->equip(cure2); // Cure default constructor
	mainCharacter->equip(ice1); // slot is full
	mainCharacter->equip(new Ice); // slot is full
	
	// use
	mainCharacter->use(0, *enemy); // at slot 0
	mainCharacter->use(1, *enemy); // at slot 1
	mainCharacter->use(2, *enemy); // at slot 2
	mainCharacter->use(3, *enemy); // at slot 3
	mainCharacter->use(4, *enemy); // out of range

	// uniquip
	mainCharacter->unequip(0); // uneuip 0
	mainCharacter->unequip(1); // uneuip 1
	mainCharacter->unequip(2); // uneuip 2
	mainCharacter->unequip(3); // uneuip 3
	mainCharacter->unequip(4); // out of range

	// learnMateria
	ms->learnMateria(new Ice); // at slot 0
	ms->learnMateria(new Cure); // at slot 1
	ms->learnMateria(new Ice); // at slot 2
	ms->learnMateria(new Cure); // at slot 3
	ms->learnMateria(new Cure); // slot is full

	// createMateria
	enemy->equip(ms->createMateria("ice"));
	enemy->equip(ms->createMateria("cure"));
	enemy->equip(ms->createMateria("ice"));
	enemy->equip(ms->createMateria("cure"));
	enemy->equip(ms->createMateria("undefined"));

	// use
	enemy->use(0, *mainCharacter);
	enemy->use(1, *mainCharacter);
	enemy->use(2, *mainCharacter);
	enemy->use(3, *mainCharacter);
	enemy->use(4, *mainCharacter);

	delete ms;
	delete mainCharacter;
	delete enemy;
	delete ice1;
	delete ice2;
	delete cure1;
	delete cure2;
	
}

void	subjectTest( void ) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

int main()
{
	atexit(func);
	std::cout << "=============== subject test ===============" << std::endl;
	subjectTest();
	std::cout << std::endl << std::endl;
	std::cout << "=============== my test ===============" << std::endl;
	MyTest();
	std::cout << std::endl << std::endl;
	return 0;
}
