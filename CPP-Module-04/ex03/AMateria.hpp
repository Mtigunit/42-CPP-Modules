# pragma once
# include <string>
# include "ICharacter.hpp"

#ifndef	AMATERIA_HPP
# define AMATERIA_HPP
class AMateria {
	protected:
		std::string	type;
	public:
		AMateria();
		AMateria(const AMateria& Copy);
		virtual	~AMateria();
		// AMateria&	operator=(const AMateria& src); /* copying the type doesn’t makesense. */
	
		AMateria(std::string const& type);
		std::string const& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP