#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog( void );
		Dog( const Dog& Copy);
		~Dog( void );
		Dog&	operator= (const Dog& src);
		void	makeSound( void ) const;
		Brain*	getBrain( void ) const;
		void	setBrain( Brain& brain );
};

#endif// DOG_HPP