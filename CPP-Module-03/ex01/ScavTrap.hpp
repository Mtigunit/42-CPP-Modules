#pragma once
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

/* ====================================================*/
/*                    derived class                    */
/* ====================================================*/

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

/*
	As you can see, the derived class destructor is called first (Derived destructor),
	and then the base class destructor is called (Base destructor).
	This order ensures that the derived class cleans up
	its resources before the base class.

	If the order were reversed, with the base class destructor called first, 
	it could lead to potential issues. For example, 
	if the derived class relies on base class resources, 
	and those resources were already destroyed before the derived class 
	destructor had a chance to clean up, 
	it could result in undefined behavior or errors.

	By calling the base class destructor after the derived class destructor completes, 
	C++ ensures that objects are properly cleaned up in the reverse order of construction,
	allowing each class to release its resources and perform 
	any necessary cleanup operations.

	It's worth noting that this behavior is automatic
	and part of the language rules for object destruction in C++.
*/