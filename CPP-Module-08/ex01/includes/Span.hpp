/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:36:41 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/24 11:21:09 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <iterator>

/* ****************************** */
/*           Span class           */
/* ****************************** */

class Span {
	private:
		std::vector<int>	arr;
	public:
		Span();
		Span(const Span& copy);
		Span&	operator=(const Span& src);
		~Span();

		Span(unsigned int N);

		void	addNumber(int toAdd);
		int		shortestSpan();
		int		longestSpan();

		void	addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
};
