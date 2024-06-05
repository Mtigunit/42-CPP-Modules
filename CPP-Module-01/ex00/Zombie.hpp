#pragma once
#include <iostream>

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie( const std::string zombieName );
		~Zombie( void );
		void		announce( void );
		void		setName( std::string name );
		std::string	getName( void );
};

Zombie* newZombie( std::string name );
void	randomChump( const std::string name );

#endif /* ZOMBIE_HPP */