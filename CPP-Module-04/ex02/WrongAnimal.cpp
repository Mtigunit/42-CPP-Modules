#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("wrong-animal") {
	std::cout << "WrongAnimal's default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& Copy) {
	std::cout << "WrongAnimal's copy constructor called." << std::endl;
	*this = Copy;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal's destructor called." << std::endl;
}

WrongAnimal&	WrongAnimal::operator= (const WrongAnimal& src) {
	std::cout << "WrongAnimal's assign operator called." << std::endl;
	this->type = src.type;
	return (*this);
}

std::string WrongAnimal::getType( void ) const {
	return (type);
}

void	WrongAnimal::setType( std::string type ) {
	this->type = type;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Wrong unknown sound." << std::endl;
}
