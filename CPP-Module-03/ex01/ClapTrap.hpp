#pragma once
#include <string>
#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/* ====================================================*/
/*                      Bass class                     */
/* ====================================================*/

class ClapTrap {
	protected:
		std::string		name;
		unsigned int	Health;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

	public:
		ClapTrap( void );
		ClapTrap(ClapTrap& Copy);
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap&	operator= (ClapTrap& src);
		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
