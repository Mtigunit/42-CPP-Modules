/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:08:24 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/20 14:59:56 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

void	increment(int& a) {
	std::cout << ++a << " ";
}

void	doSomthing(int a) {
	if (a % 2 == 0) {
		std::cout << "hello! ";
	} else {
		std::cout << "get out! ";
	}
}

template <typename T>
void	tmpFunc(T a) {
	std::cout << a + 3 << std::endl;
}

int	main() {
	int	a[] = {5, 3, 2, 1, 0};

	iter(a, 5, increment);
	std::cout << "\n====\n";
	iter(a, 5, doSomthing);
	std::cout << "\n====\n";
	iter(a, 5, tmpFunc<int>);
}
