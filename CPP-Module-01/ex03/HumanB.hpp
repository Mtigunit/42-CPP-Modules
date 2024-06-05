#pragma once
#include <string>
#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB( std::string name );
		~HumanB( void );
		std::string	getName( void );
		Weapon*		getWeapon( void );
		void		setName( std::string name );
		void		setWeapon( Weapon weapon );
		void		attack( void );
};

#endif /* HUMANB_HPP */