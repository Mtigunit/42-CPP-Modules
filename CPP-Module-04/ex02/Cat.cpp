#include "Cat.hpp"

Cat::Cat( void ) : _brain(new Brain) {
	std::cout << "Cat's default constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat( const Cat& Copy) {
	std::cout << "Cat's copy constructor called." << std::endl;
	*this = Copy;
}

Cat::~Cat( void ) {
	std::cout << "Cat's destructor called." << std::endl;
	delete _brain;
}

Cat&	Cat::operator= (const Cat& src) {
	std::cout << "Cat's assignement operator called." << std::endl;
	if (this != &src) {
		this->_type = src._type;
		if (src._brain) {
			_brain = new Brain(*src._brain);
		}
	}
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << "🐱Meow Meow🐱" << std::endl;
}

Brain*	Cat::getBrain( void ) const {
	return (this->_brain);
}

void	Cat::setBrain(Brain& brain) {
	if (_brain) {
		delete _brain;
	}
	this->_brain = &brain;
}
