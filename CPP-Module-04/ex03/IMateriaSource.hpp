# pragma once
# include <string>
# include "AMateria.hpp"

#ifndef IMATERIASOURSES_HPP
# define IMATERIASOURSES_HPP

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // IMATERIASOURSES_HPP
