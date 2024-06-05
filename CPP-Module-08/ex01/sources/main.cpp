/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:35:23 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/24 12:11:16 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>

int main()
{
	std::vector<int>	vec;
 	Span sp(5);
	
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(9);
	vec.push_back(11);

	sp.addRange(vec.begin(), vec.end());
	
	std::cout << "shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest Span: " << sp.longestSpan() << std::endl;
	
	try {
		sp.addNumber(2);
		sp.addNumber(1);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	return (0);
}
