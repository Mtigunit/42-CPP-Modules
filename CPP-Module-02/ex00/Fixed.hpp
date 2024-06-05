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
		Fixed( const Fixed& Copy );
		Fixed& operator = (const Fixed &src);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif // FIXED_HPP
