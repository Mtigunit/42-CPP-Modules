#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain's default constructor called." << std::endl;
	for (size_t i = 0; i < 100; i++) {
		_ideas[i] = "Winner's Mindset";
	}
}

Brain::Brain( const Brain& Copy) {
	std::cout << "Brain's copy constructor called." << std::endl;
	*this = Copy;
}

Brain::~Brain( void ) {
	std::cout << "Brain's destructor called." << std::endl;
}

Brain&	Brain::operator= (const Brain& src) {
	std::cout << "Brain's assign operator called." << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = src._ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdeas( unsigned int index ) {
	if (index > 99) {
		std::cout << "OutOfRange\n";
		return (NULL);
	}
	return (_ideas[index]);
}

void	Brain::setIdeas( unsigned int index, std::string& idea ) {
	if (index > 99) {
		std::cout << "OutOfRange\n";
		return ;
	}
	_ideas[index] = idea;
}
