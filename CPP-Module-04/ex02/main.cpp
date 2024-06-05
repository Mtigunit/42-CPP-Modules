#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void	subjectTest( void ) {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete j;
	delete i;
}

void	brainTest( void ) {
	Cat *cat = new Cat;
	Brain *brain = new Brain;
	Dog ref;
	Dog dog = ref;
	Dog ref2;
	Dog dog2(ref2);

	if (dog.getBrain() == ref.getBrain()) {
		std::cout << "WARNING: Shallow copy!" << std::endl;
	}
	if (dog2.getBrain() == ref2.getBrain()) {
		std::cout << "WARNING: Shallow copy!2" << std::endl;
	}
	cat->setBrain(*brain);
	std::cout << brain->getIdeas(0) << std::endl;
	std::string newIdea = "*new idea*";
	brain->setIdeas(0, newIdea);
	std::cout << brain->getIdeas(0) << std::endl;
	
	delete cat;
}

void	myTest( void ) {
	const WrongAnimal* wronganimal = new WrongAnimal;
	const WrongAnimal* wrongCat = new WrongCat;
	Animal* cat = new Cat;
	Cat* copy = new Cat;
	Animal*	CopyCat = new Cat(*copy);
	Animal* src = new Dog;
	Animal* dog = src;

	std::cout << wronganimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << copy->getType() << std::endl;
	std::cout << CopyCat->getType() << std::endl;
	std::cout << src->getType() << std::endl;

	cat->setType("sameTypeForAll");
	dog->setType("sameTypeForAll");
	copy->setType("sameTypeForAll");
	CopyCat->setType("sameTypeForAll");
	src->setType("sameTypeForAll");


	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << copy->getType() << std::endl;
	std::cout << CopyCat->getType() << std::endl;
	std::cout << src->getType() << std::endl;

	wronganimal->makeSound();
	wrongCat->makeSound();
	cat->makeSound();
	dog->makeSound();
	copy->makeSound();
	CopyCat->makeSound();
	src->makeSound();

	delete wronganimal;
	delete wrongCat;
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
	std::cout << "\n\n=================== brain test ====================\n";
	brainTest();
	return (0);
}
