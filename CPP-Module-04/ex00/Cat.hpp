#pragma once
#include "Animal.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal {
	public:
		Cat( void );
		Cat( const Cat& Copy );
		~Cat( void );
		Cat&	operator= ( const Cat& src );

		void	makeSound( void ) const;
};

#endif// CAT_HPP