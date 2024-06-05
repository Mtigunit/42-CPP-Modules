/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:50 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/20 14:36:56 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/templates.hpp"

void	myTest() {
	int	a = 1, b = 2;
	std::cout << "********* int *********" << std::endl;
	std::cout << "==== befor swap ====" << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	swap(a, b);
	std::cout << "==== after swap ====" << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;

	std::cout << "==== min ====" << std::endl;
	std::cout << "min is: " << min(a, b) << std::endl;
	std::cout << "==== max ====" << std::endl;
	std::cout << "max is: " << max(a, b) << std::endl;

	float	c = 1.3, d = 1.2;
	std::cout << std::endl;
	std::cout << "********* float *********" << std::endl;
	std::cout << "==== befor swap ====" << std::endl;
	std::cout << "c: " << c << " d: " << d << std::endl;
	swap(c, d);
	std::cout << "==== after swap ====" << std::endl;
	std::cout << "a: " << c << " d: " << d << std::endl;

	std::cout << "==== min ====" << std::endl;
	std::cout << "min is: " << min(c, d) << std::endl;
	std::cout << "==== max ====" << std::endl;
	std::cout << "max is: " << max(c, d) << std::endl;
}

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	myTest();
	return 0;
}
