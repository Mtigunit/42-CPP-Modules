#pragma once
#include <string>
#include <iostream>

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

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

#endif// WRONGANIMAL_HPP
