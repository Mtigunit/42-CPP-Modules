#pragma once
#include <string>
#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon( std::string type );
		~Weapon( void );
		const std::string&	getType( void );
		void				setType( const std::string type );
};

#endif /* WEAPON_HPP */