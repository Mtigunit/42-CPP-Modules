/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:10:59 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/18 10:17:40 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <cmath>

Base * generate(void) {
	std::srand(std::time(NULL));
    int n = (std::rand() % 3) + 1;
	if (n == 1) {
		return (new A);
	} else if (n == 2) {	
		return (new B);
	} else {
		return (new C);
	}
	return (nullptr);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "class A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "class B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "class C" << std::endl;
	} else {
		std::cout << "Unknown type!" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "class A" << std::endl;
		(void)a;
	} catch (std::exception &e) {
		try {
			B& b = dynamic_cast<B&>(p);
			std::cout << "class B" << std::endl;
			(void)b;
		} catch (std::exception &e) {
			try	{
				C& c = dynamic_cast<C&>(p);
				std::cout << "class C" << std::endl;
				(void)c;
			} catch (std::exception &e) {
				std::cout << "Unknown type!\n";
			}
		}
	}
}

class D : public Base {};

int	main() {
	A a;
	B b;
	C c;
	D d;

	Base& ref_a = a;
	Base& ref_b = b;
	Base& ref_c = c;
	Base& ref_d = d;

	std::cout << "random: ";
	identify(generate());
	std::cout << std::endl;


	std::cout << "ref_a: ";
	identify(ref_a);
	std::cout << "ref_b: ";
	identify(ref_b);
	std::cout << "ref_c: ";
	identify(ref_c);
	std::cout << "ref_d: ";
	identify(ref_d);
	

	return (0);
}
