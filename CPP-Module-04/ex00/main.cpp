#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	subjectTest( void ) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void	myTest( void ) {
	const WrongAnimal* wronganimal = new WrongAnimal;
	const WrongAnimal* wrongCat = new WrongCat;
	Animal*	animal = new Animal;
	Animal* cat = new Cat;
	Cat* copy = new Cat;
	Animal*	CopyCat = new Cat(*copy);
	Animal* src = new Dog;
	Animal* dog = src;

	std::cout << wronganimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;
	std::cout << animal->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << copy->getType() << std::endl;
	std::cout << CopyCat->getType() << std::endl;
	std::cout << src->getType() << std::endl;

	// wronganimal->setType("sameTimeForAll"); // i can't set type because the var is cnost
	animal->setType("sameTypeForAll");
	cat->setType("sameTypeForAll");
	dog->setType("sameTypeForAll");
	copy->setType("sameTypeForAll");
	CopyCat->setType("sameTypeForAll");
	src->setType("sameTypeForAll");


	std::cout << animal->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << copy->getType() << std::endl;
	std::cout << CopyCat->getType() << std::endl;
	std::cout << src->getType() << std::endl;

	wronganimal->makeSound();
	wrongCat->makeSound();
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	copy->makeSound();
	CopyCat->makeSound();
	src->makeSound();

	delete wronganimal;
	delete wrongCat;
	delete animal;
	delete cat;
	delete copy;
	delete CopyCat;
	delete src;
}

void	func( void ) {
	system("leaks program");
}

int main()
{
	atexit(func);
	std::cout << "\n\n================== subject test ==================\n";
	subjectTest();
	std::cout << "\n\n==================== my test =====================\n";
	myTest();
	return (0);
}
