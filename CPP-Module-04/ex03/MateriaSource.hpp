# pragma once
# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

#ifndef MATERIASOURSES_HPP
# define MATERIASOURSES_HPP

class MateriaSource : public IMateriaSource {
	private:
		AMateria* msInventory[4];
	public:
		MateriaSource();
		MateriaSource( const MateriaSource& Copy );
		MateriaSource&	operator=( const MateriaSource& src);
		~MateriaSource();
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURSES_HPP
