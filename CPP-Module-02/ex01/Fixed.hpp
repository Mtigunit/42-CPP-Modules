#pragma once
#include "Fixed.hpp"
#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed
{
	private:
		int					raw;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		Fixed( const Fixed& Copy );
		Fixed& operator = (const Fixed &src);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP
