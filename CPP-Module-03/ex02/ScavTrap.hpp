#pragma once
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( ScavTrap& Copy );
		~ScavTrap( void );
		ScavTrap& operator= (const ScavTrap& src);

		ScavTrap( std::string name );
		void	attack(const std::string& target);
		void	guardGate( void );
};

#endif // SCAVTRAP_HPP
