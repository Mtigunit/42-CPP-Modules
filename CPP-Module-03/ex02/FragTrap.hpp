#pragma once
#include <string>
#include <iostream>
#include "ScavTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : public ClapTrap {
	public:
		FragTrap( void );
		FragTrap(FragTrap& Copy);
		~FragTrap();
		FragTrap&	operator= (const FragTrap& src);
		FragTrap(std::string name);
		void	highFivesGuys( void );
};

#endif // FRAGTRAP_HPP