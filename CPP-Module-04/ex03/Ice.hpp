# pragma once
# include <string>
# include "AMateria.hpp"

#ifndef ICE_HPP
# define ICE_HPP

class Ice : public AMateria {
	public:
		Ice();
		Ice( const Ice& Copy);
		~Ice();
		Ice&	operator=( const Ice& src);
		AMateria* clone() const ;
		void use(ICharacter& target);
};

#endif // ICE_HPP
