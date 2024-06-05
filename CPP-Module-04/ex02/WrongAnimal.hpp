#pragma once
#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& Copy);
		virtual	~WrongAnimal( void );
		WrongAnimal&	operator= (const WrongAnimal& src);
		std::string	getType( void ) const ;
		void			setType( std::string type );
		void	makeSound( void ) const ;
};
