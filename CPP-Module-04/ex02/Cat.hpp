#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat( void );
		Cat( const Cat& Copy);
		~Cat( void );
		Cat&	operator= (const Cat& src);
		void  	makeSound( void ) const;
		Brain*	getBrain( void ) const;
		void	setBrain( Brain& brain );
};