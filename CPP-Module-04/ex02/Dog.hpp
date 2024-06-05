#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

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
