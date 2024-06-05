# C++ Module 00 - Namespaces, Classes, Member Functions, and More

This repository contains the solutions to the exercises of Module 00 from C++ modules. In this module, we cover the basics of C++ programming, including namespaces, classes, member functions, stdio streams, initialization lists, static, const, and other fundamental concepts.

## Table of Contents

1. [Introduction](#introduction)
2. [General Rules](#general-rules)
3. [Exercise 00: Megaphone](#exercise-00-megaphone)
4. [Exercise 01: My Awesome PhoneBook](#exercise-01-my-awesome-phonebook)
5. [Exercise 02: The Job Of Your Dreams](#exercise-02-the-job-of-your-dreams)

## Introduction

C++ is a powerful and versatile programming language, extending the capabilities of the C programming language and introducing the concepts of Object-Oriented Programming (OOP). This module serves as a starting point for your C++ journey, introducing essential concepts step-by-step.

Throughout this module, we will adhere to the C++98 standard to keep things simple and focus on core principles. Although modern C++ has evolved significantly, mastering C++98 forms a solid foundation for becoming a proficient C++ developer.

## General Rules

To ensure consistency and best practices, the following general rules should be followed when working on the exercises:

- Compile your code with `c++` and the flags `-Wall -Wextra -Werror` to catch potential issues and ensure clean code.
- Your code should comply with the C++98 standard to maintain uniformity across all exercises.
- Follow appropriate formatting and naming conventions for classes, functions, and files. Class names should be in UpperCamelCase format.
- Output messages should end with a new-line character and be displayed to the standard output.
- While no specific coding style is enforced, strive to write clean and readable code to aid peer evaluation.

### Allowed/Forbidden

- You are allowed to use almost everything from the standard library, favoring C++-ish versions of C functions.
- However, external libraries like C++11 and Boost are forbidden.
- Forbidden functions include `printf()`, `alloc()`, and `free()`. Use their C++ alternatives instead.
- Avoid using `using namespace <ns_name>` and `friend` keywords.
- STL usage is restricted until Module 08 and 09.

## Exercise 00: Megaphone

Implement a program named `megaphone` that converts input text to uppercase. The program should take a string as input and display the converted text to the standard output. Examples:

```
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

## Exercise 01: My Awesome PhoneBook

Implement a simple phonebook software that can store up to 8 contacts. The user can add new contacts and search for existing ones. The phonebook should be designed using two classes: `PhoneBook` and `Contact`.

The `PhoneBook` class should have the following features:

- It contains an array of `Contact` objects to store the contacts.
- The phonebook can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one with the new one.
- Dynamic allocation is forbidden; the phonebook must work with static arrays.

The `Contact` class should represent a phonebook contact and have the following fields:

- First name
- Last name
- Nickname
- Phone number
- Darkest secret

On program start-up, the phonebook is empty, and the user is prompted to enter one of three commands: ADD, SEARCH, or EXIT. The program only accepts these commands.

- ADD: Save a new contact.
  - If the user enters this command, they are prompted to input the information of the new contact one field at a time. Once all the fields have been completed, add the contact to the phonebook.
  - A saved contact can't have empty fields.
- SEARCH: Display a specific contact.
  - Display the saved contacts as a list of 4 columns: index, first name, last name, and nickname.
  - Each column must be 10 characters wide, and the text must be right-aligned. If the text is longer than the column, truncate it and replace the last displayable character with a dot (`.`).
  - Prompt the user again for the index of the entry to display. If the index is out of range or incorrect, handle it appropriately. Otherwise, display the contact information, one field per line.
- EXIT: The program quits, and the contacts are lost forever!

Any other input is discarded. The program should continue to wait for commands until the user inputs EXIT.

## Exercise 02: The Job Of Your Dreams

In this exercise, you are tasked with recreating a missing source file, `Account.cpp`, using the provided `Account.hpp` header file and the log file. The goal is to implement the `Account` class, ensuring that it passes the provided tests.

Please refer to the provided `Account.hpp`, `tests.cpp`, and log file for details on the `Account` class's expected behavior and interface.

## Conclusion

Congratulations on completing the C++ Module 00! By mastering namespaces, classes, member functions, and other essential concepts, you are now well-equipped to tackle more complex C++ challenges.

Remember to continue exploring and practicing, as C++ offers a vast array of possibilities and can be an incredibly powerful language when used effectively. Good luck with your future coding endeavors! If you have any questions or need assistance, don't hesitate to reach out. Happy coding!
