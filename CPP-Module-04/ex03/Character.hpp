# pragma once
# include <string>
# include "AMateria.hpp"

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class AMateria;
class Character : public ICharacter {
	private:
		std::string	name;
		AMateria*	Inventory[4];
	public:
		// Character();
		Character( const std::string name );
		Character( const Character& Copy);
		~Character();
		Character&	operator=( const Character& src);
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif // CHARACTER_HPP