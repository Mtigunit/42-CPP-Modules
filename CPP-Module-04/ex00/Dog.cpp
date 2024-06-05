#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog's default constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog( const Dog& Copy) {
	std::cout << "Dog's copy constructor called." << std::endl;
	*this = Copy;
}

Dog::~Dog( void ) {
	std::cout << "Dog's destructor called." << std::endl;
}

Dog&	Dog::operator= (const Dog& src) {
	std::cout << "Dog's assign operator called." << std::endl;
	if (this != &src) {
		this->_type = src._type;
	}
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << "🐕Woof woof🐕" << std::endl;
}
