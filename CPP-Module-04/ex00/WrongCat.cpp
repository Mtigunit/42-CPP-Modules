#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	std::cout << "WrongCat's default constructor called." << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& Copy) {
	std::cout << "WrongCat's copy constructor called." << std::endl;
	*this = Copy;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat's destructor called." << std::endl;

}

WrongCat&	WrongCat::operator= (const WrongCat& src) {
	std::cout << "WrongCat's assign operator called." << std::endl;
	this->type = src.type;
	return (*this);
}

void	WrongCat::makeSound( void ) const {
	std::cout << "WrongCat's sound." << std::endl;
}
