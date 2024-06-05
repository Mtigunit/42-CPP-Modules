/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:32:36 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/24 11:25:42 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <exception>
#include <iostream>

/* ********************************** */
/*         Orthodox Canonical         */
/* ********************************** */

Span::Span(const Span& copy) {
	*this = copy;
}

Span&	Span::operator=(const Span& src) {
	if (this != &src) {
		arr = src.arr;
	}
	return (*this);
}

Span::Span() {}

Span::~Span() {}

/* ******************************* */
/*         Other Functions         */
/* ******************************* */

Span::Span(unsigned int N) {
	arr.reserve(N);
}

void	Span::addNumber(int toAdd) {
	if (arr.size() < arr.capacity()) {
		arr.push_back(toAdd);
	} else {
		throw std::runtime_error("Span is full :(\n");
	}
}

int Span::shortestSpan() {
	if (arr.size() < 2) {
		throw std::runtime_error("Not enough numbers to calculate span");
	}

	std::vector<int> tmp = arr;
	std::sort(tmp.begin(), tmp.end());
	int minSpan = tmp[1] - tmp[0];
	for	(size_t i = 1; i < tmp.size(); i++) {
		if ((tmp[i] - tmp[i - 1]) < minSpan)
			minSpan = tmp[i] - tmp[i - 1];
	}

	return minSpan;
}

int Span::longestSpan() {
	if (arr.size() < 2) {
		throw std::runtime_error("Not enough numbers to calculate span");
	}

	std::vector<int> tmp = arr;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

void	Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	while (first < last) {
		arr.push_back(*first);
		first++;
	}
}
