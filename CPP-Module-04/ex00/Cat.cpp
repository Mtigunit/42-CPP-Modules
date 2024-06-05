#include "Cat.hpp"

Cat::Cat( void ) {
	std::cout << "Cat's default constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat( const Cat& Copy) {
	std::cout << "Cat's copy constructor called." << std::endl;
	*this = Copy;
}

Cat::~Cat( void ) {
	std::cout << "Cat's destructor called." << std::endl;
}

Cat&	Cat::operator= (const Cat& src) {
	std::cout << "Cat's assign operator called." << std::endl;
	if (this != &src) {
		_type = src._type;
	}
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << "🐱Meow Meow🐱" << std::endl;
}
