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

		bool operator< (const Fixed &src);
		bool operator> (const Fixed &src);
		bool operator<= (const Fixed &src);
		bool operator>= (const Fixed &src);
		bool operator== (const Fixed &src);
		bool operator!= (const Fixed &src);
	
		Fixed operator+ (const Fixed &src);
		Fixed operator- (const Fixed &src);
		Fixed operator/ (const Fixed &src);
		Fixed operator* (const Fixed &src);
	
		Fixed operator++(int); // Overloading post-increment operator (x++)
		Fixed& operator++(); // Overloading pre-increment operator (++x) 
		Fixed operator--(int); // Overloading post-decrement operator (x--)
		Fixed& operator--(); // Overloading pre-decrement operator (--x)

		static Fixed& min(Fixed& fp1, Fixed& fp2);
		static const Fixed& min(const Fixed& fp1, const Fixed& fp2);
		static Fixed& max(Fixed& fp1, Fixed& fp2);
		static const Fixed& max(const Fixed& fp1, const Fixed& fp2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP
