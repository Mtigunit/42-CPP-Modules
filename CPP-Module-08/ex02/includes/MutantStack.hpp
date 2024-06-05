/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:09:16 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/24 12:20:27 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

/* ******************************* */
/*        MutantStack class        */
/* ******************************* */

template <typename Tstack>
class MutantStack : public std::stack<Tstack> {
	public:
		typedef typename std::stack<Tstack>::container_type::iterator		iterator;
		typedef typename std::stack<Tstack>::container_type::const_iterator	const_iterator;
		MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack&	operator=(const MutantStack& src);
		~MutantStack();

		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

/* ********************************** */
/*         Orthodox Canonical         */
/* ********************************** */

template <typename Tstack>
MutantStack<Tstack>::MutantStack() : std::stack<Tstack>() {}

template <typename Tstack>
MutantStack<Tstack>::MutantStack(const MutantStack& copy) : std::stack<Tstack>(copy) {}

template <typename Tstack>
MutantStack<Tstack>&	MutantStack<Tstack>::operator=(const MutantStack<Tstack>& src) {
	if (this != &src) {
		std::stack<Tstack>::operator=(src);
	}
	return *this;
}

template <typename Tstack>
MutantStack<Tstack>::~MutantStack() {}

/* ******************************* */
/*         Other Functions         */
/* ******************************* */

template <typename Tstack>
typename MutantStack<Tstack>::iterator MutantStack<Tstack>::begin() {
    return this->c.begin();
}

template <typename Tstack>
typename MutantStack<Tstack>::iterator MutantStack<Tstack>::end() {
    return this->c.end();
}

template <typename Tstack>
typename MutantStack<Tstack>::const_iterator MutantStack<Tstack>::begin() const {
    return this->c.begin();
}

template <typename Tstack>
typename MutantStack<Tstack>::const_iterator MutantStack<Tstack>::end() const {
    return this->c.end();
}
