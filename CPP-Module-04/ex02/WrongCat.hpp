#pragma once
#include "WrongAnimal.hpp"
#include "Brain.hpp"

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
