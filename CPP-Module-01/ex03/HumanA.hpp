#pragma once
#include <string>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );
		std::string	getName( void );
		Weapon&		getWeapon( void );
		void		setName( std::string name );
		void		setWeapon( Weapon weapon );
		void		attack( void );
};

#endif /* HUMANA_HPP */