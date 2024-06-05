#pragma once
#include <string>
#include <iostream>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain( void );
		Brain( const Brain& Copy);
		~Brain( void );
		Brain&	operator= (const Brain& src);

		std::string	getIdeas( unsigned int index );
		void		setIdeas( unsigned int index, std::string& idea );
};

#endif// BRAIN_HPP