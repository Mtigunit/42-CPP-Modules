# C++ Module 03 Exercises

This repository contains the exercises of Module 03 from the C++ course, focusing on Inheritance.

## Introduction

C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language. These modules introduce Object-Oriented Programming (OOP) concepts in C++. The exercises will cover topics related to inheritance and class hierarchies.

## Exercise 00: Aaaaand... OPEN!

Create a class called `ClapTrap` with the following private attributes:

- `Name`: The name of the ClapTrap (passed as a parameter to the constructor).
- `Hit points`: Represents the health of the ClapTrap (initialized to 10).
- `Energy points`: Represents the energy of the ClapTrap (initialized to 10).
- `Attack damage`: Represents the damage caused by the ClapTrap (initialized to 0).

The class should have the following public member functions:

- `ClapTrap(const std::string& name);`: The constructor that initializes the name of the ClapTrap.
- `void attack(const std::string& target);`: Causes the ClapTrap to attack the target, reducing its hit points and energy points. The function should display a message indicating the attack.
- `void takeDamage(unsigned int amount);`: Reduces the ClapTrap's hit points by the given amount. The function should display a message indicating the amount of damage taken and the remaining hit points.
- `void beRepaired(unsigned int amount);`: Increases the ClapTrap's hit points by the given amount. The function should display a message indicating the amount of hit points repaired and the total hit points.

## Exercise 01: Serena, my love!

Create a class called `ScavTrap` that inherits from `ClapTrap`. The `ScavTrap` class should have its own attributes:

- `Hit points`: Represents the health of the ScavTrap (initialized to 100).
- `Energy points`: Represents the energy of the ScavTrap (initialized to 50).
- `Attack damage`: Represents the damage caused by the ScavTrap (initialized to 20).

The class should have the following member function:

- `ScavTrap(const std::string& name);`: The constructor that initializes the name of the ScavTrap and invokes the base class constructor to initialize the ClapTrap's name.
- `void guardGate();`: Displays a message informing that the ScavTrap is now in Gatekeeper mode.

## Exercise 02: Repetitive work

Create a class called `FragTrap` that inherits from `ClapTrap`. The `FragTrap` class should have its own attributes:

- `Hit points`: Represents the health of the FragTrap (initialized to 100).
- `Energy points`: Represents the energy of the FragTrap (initialized to 100).
- `Attack damage`: Represents the damage caused by the FragTrap (initialized to 30).

The class should have the following member function:

- `FragTrap(const std::string& name);`: The constructor that initializes the name of the FragTrap and invokes the base class constructor to initialize the ClapTrap's name.
- `void highFivesGuys();`: Displays a positive high fives request on the standard output.

---

For each exercise, make sure to implement the class definitions and their member functions in separate `.cpp` and `.hpp` files. Properly manage memory allocation and deallocation and follow the guidelines specified in the general rules section. Add thorough tests to your program to ensure that the classes behave as expected.
