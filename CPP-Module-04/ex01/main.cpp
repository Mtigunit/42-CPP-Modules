#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void func( void ) {
	std::system("leaks program");
}

int main( void ) {
	std::atexit(func);

    const int animalCount = 10;
    Animal* animals[animalCount];

    for (int i = 0; i < animalCount / 2; i++) {
        animals[i] = new Dog();
    }

    for (int i = animalCount / 2; i < animalCount; i++) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < animalCount; i++) {
        std::cout << "type : " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < animalCount; i++) {
        delete animals[i];
    }
    return 0;
}
