#pragma once
#include "Animal.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal {
	public:
		Dog( void );
		Dog( const Dog& Copy);
		~Dog( void );
		Dog&	operator= (const Dog& src);
		void	makeSound( void ) const;
};

#endif// DOG_HPP