#pragma once
#include "WrongAnimal.hpp"
#include "Brain.hpp"

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

class WrongCat : public WrongAnimal {
	private:
		Brain* _brain;
	public:
		WrongCat( void );
		WrongCat( const WrongCat& Copy);
		~WrongCat( void );
		WrongCat&	operator= (const WrongCat& src);
		void	makeSound( void ) const;
};

#endif// WRONGCAT_HPP