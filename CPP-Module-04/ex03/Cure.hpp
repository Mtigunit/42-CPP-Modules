# pragma once
# include <string>
# include "AMateria.hpp"

#ifndef CURE_HPP
# define CURE_HPP

class Cure : public AMateria {
	public:
		Cure();
		Cure( const Cure& Copy);
		~Cure();
		Cure&	operator=( const Cure& src);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif // CURE_HPP
