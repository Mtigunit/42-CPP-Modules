#include "Fixed.hpp"

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called" << std::endl;
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
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->raw);
}

void	Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	raw = integer << fractionalBits;
} // convert an integer value to a fixed-point representation

Fixed::Fixed(const float floatingPoint) {
	std::cout << "Float constructor called" << std::endl;
	raw = roundf(floatingPoint * (1 << fractionalBits));
} // convert a floating-point number to a fixed-point representation

float	Fixed::toFloat( void ) const {
	return ((float)raw / (1 << fractionalBits));
} // convert a fixed-point value to a floating-point representation

int	Fixed::toInt( void ) const {
	return (raw >> fractionalBits);
} // convert a fixed-point value to an integer representation

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
} // output a fixed-point value as a floating-point value
