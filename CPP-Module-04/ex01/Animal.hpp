#pragma once
#include <string>
#include <iostream>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal {
	protected:
		std::string _type;
	public:
		Animal( void );
		Animal( const Animal& Copy );
		virtual	~Animal( void );
		Animal&	operator= ( const Animal& src );
		std::string	getType( void ) const ;
		void			setType( std::string type );
		void virtual	makeSound( void ) const ;
};

#endif// ANIMAL_HPP