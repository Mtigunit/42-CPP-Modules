#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}

Fixed::Fixed( const Fixed& Copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = Copy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &src)  {
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (raw);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}
