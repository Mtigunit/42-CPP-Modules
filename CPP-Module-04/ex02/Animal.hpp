#pragma once
#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal( void );
		Animal( const Animal& Copy);
		Animal&	operator= (const Animal& src);
		virtual	~Animal( void );

		std::string		getType( void ) const;
		void			setType( std::string type );
		virtual void	makeSound( void ) const = 0;
};