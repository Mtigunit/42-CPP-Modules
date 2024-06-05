#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

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

#endif// CAT_HPP