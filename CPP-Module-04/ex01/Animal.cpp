#include "Animal.hpp"

Animal::Animal( void ) : _type("unknown") {
	std::cout << "Animal's default constructor called." << std::endl;
}

Animal::Animal( const Animal& Copy) {
	std::cout << "Animal's copy constructor called." << std::endl;
	*this = Copy;
}

Animal::~Animal( void ) {
	std::cout << "Animal's destructor called." << std::endl;
}

Animal&	Animal::operator= (const Animal& src) {
	std::cout << "Animal's assign operator called." << std::endl;
	this->_type = src._type;
	return (*this);
}

std::string Animal::getType( void ) const {
	return (_type);
}

void	Animal::setType( std::string type ) {
	this->_type = type;
}

void	Animal::makeSound( void ) const {
	std::cout << "unknown sound." << std::endl;
}
