# C++ Module 04 - Polymorphism, Abstract Classes, Interfaces

## Introduction
Welcome to Module 04 of the C++ course! In this module, we will focus on concepts related to polymorphism, abstract classes, and interfaces. We will build upon the knowledge gained from previous modules and delve deeper into Object-Oriented Programming with C++.

## Exercise 00: Polymorphism
In this exercise, you'll implement a simple base class called `Animal` and derived classes `Dog` and `Cat`. Each animal will have a specific `type`, and they will be able to `makeSound()` accordingly.

### Instructions
- Implement the `Animal` class with a protected attribute `std::string type`.
- Implement the `Dog` and `Cat` classes that inherit from `Animal`, setting their `type` accordingly.
- Each animal must be able to use the member function `makeSound()` to print the appropriate sound.

### Example
```cpp
// Sample usage of the classes
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // Output: "Cat sound"
    j->makeSound(); // Output: "Dog sound"
    meta->makeSound(); // Output: "Animal sound"
    // Remember to deallocate memory and handle any potential memory leaks.
    return 0;
}
```

## Exercise 01: I Don’t Want to Set the World on Fire
In this exercise, you'll implement the `Brain` class, containing an array of 100 `std::string` called `ideas`. Then, you'll update the `Dog` and `Cat` classes to have a private `Brain*` attribute, which will be created and deleted upon construction and destruction of each animal, respectively.

### Instructions
- Implement the `Brain` class with an array of 100 `std::string` called `ideas`.
- Update the `Dog` and `Cat` classes to have a private `Brain*` attribute.
- Create the `Brain` object using `new Brain()` upon construction of each animal and delete it upon destruction.
- Create an array of `Animal` objects with half being `Dog` and half being `Cat`.
- At the end of the program execution, loop over the array and delete every `Animal`. Remember to check for memory leaks.

### Example
```cpp
// Sample usage of the classes
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not create a leak
    delete i;
    // Remember to deallocate memory and handle any potential memory leaks.
    return 0;
}
```

## Exercise 02: Abstract Class
In this exercise, you'll update the `Animal` class to make it an abstract class, preventing it from being instantiated directly.

### Instructions
- Update the `Animal` class to make it an abstract class.
- Ensure that the updated class behaves the same way as before.

## Exercise 03: Interface & Recap
In this final exercise, you'll implement interfaces using pure abstract classes and create concrete classes implementing the interfaces.

### Instructions
- Complete the definition of the `AMateria` class and implement the necessary member functions.
- Implement the concrete classes `Ice` and `Cure`, overriding the `clone()` and `use(ICharacter&)` functions accordingly.
- Write the `Character` class implementing the `ICharacter` interface, which has an inventory of 4 slots for `AMateria`.
- Implement the `MateriaSource` class, which implements the `IMateriaSource` interface and can learn and create new `Materia`.

### Example
```cpp
// Sample usage of the classes
int main()
{
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
    me->use(0, *bob); // Output: "* shoots an ice bolt at bob *"
    me->use(1, *bob); // Output: "* heals bob's wounds *"
    delete bob;
    delete me;
    delete src;
    // Remember to deallocate memory and handle any potential memory leaks.
    return 0;
}
```

## Conclusion
In this module, you have learned about polymorphism, abstract classes, and interfaces in C++. These concepts are fundamental in Object-Oriented Programming and provide powerful tools for building robust and flexible code.

Remember to test your code thoroughly and handle memory allocation and deallocation properly to avoid memory leaks. Happy coding!
