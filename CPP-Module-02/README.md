# C++ Module 02 Exercises

This repository contains the exercises of Module 02 from the C++ course. The exercises cover topics like ad-hoc polymorphism, operator overloading, and implementing classes in Orthodox Canonical Form.

## Introduction

C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language. This module introduces Object-Oriented Programming concepts in C++. The exercises are designed to build a solid foundation in C++ development.

## New Rules

From this point onward, all classes must be designed in the Orthodox Canonical Form. The classes should implement the following member functions:

- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

## Exercise 00: My First Class in Orthodox Canonical Form

Create a class in Orthodox Canonical Form that represents a fixed-point number:

### Class Details:

- Private members:
  - An integer to store the fixed-point number value.
  - A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.

- Public members:
  - A default constructor that initializes the fixed-point number value to 0.
  - A copy constructor.
  - A copy assignment operator overload.
  - A destructor.
  - A member function `int getRawBits() const;` that returns the raw value of the fixed-point value.
  - A member function `void setRawBits(int const raw);` that sets the raw value of the fixed-point number.

### Example Usage:

```cpp
#include <iostream>

int main() {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
```

## Exercise 01: Towards a more useful fixed-point number class

Enhance the fixed-point number class by adding constructors that take constant integers and floating-point numbers as parameters. Implement member functions to convert the fixed-point value to a floating-point value and an integer value. Also, overload the insertion operator to display the fixed-point number in the output stream.

### Class Details:

- Public constructors:
  - A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in Exercise 00.
  - A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in Exercise 00.

- Public member functions:
  - `float toFloat() const;`: Converts the fixed-point value to a floating-point value.
  - `int toInt() const;`: Converts the fixed-point value to an integer value.

- Additional function for Fixed class files:
  - Overload the insertion operator (<<) to insert a floating-point representation of the fixed-point number into the output stream.

### Example Usage:

```cpp
#include <iostream>

int main() {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
```

## Exercise 02: Now we’re talking

Overload comparison and arithmetic operators for the fixed-point number class. Implement pre-increment, post-increment, pre-decrement, and post-decrement operators to increase or decrease the fixed-point value. Add static member functions to find the minimum and maximum of two fixed-point numbers.

### Class Details:

- Overloaded operators:
  - Comparison operators: >, <, >=, <=, ==, and !=.
  - Arithmetic operators: +, -, *, and /.
  - Increment/decrement operators: ++ (pre-increment), ++ (post-increment), -- (pre-decrement), and -- (post-decrement).

- Static member functions:
  - `static Fixed &min(Fixed &a, Fixed &b);`: Returns a reference to the smallest of two fixed-point numbers.
  - `static const Fixed &min(const Fixed &a, const Fixed &b);`: Returns a reference to the smallest of two constant fixed-point numbers.
  - `static Fixed &max(Fixed &a, Fixed &b);`: Returns a reference to the greatest of two fixed-point numbers.
  - `static const Fixed &max(const Fixed &a, const Fixed &b);`: Returns a reference to the greatest of two constant fixed-point numbers.

### Example Usage:

```cpp
#include <iostream>

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}
```
