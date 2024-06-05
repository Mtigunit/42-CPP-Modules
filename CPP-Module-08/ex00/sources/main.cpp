/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:22:12 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/24 12:07:10 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <vector>
#include <iostream>

int	main() {
	std::vector<int> arr;
	arr.push_back(5);

	try {
		std::cout << *easyfind(arr, 5) << std::endl; // element found
		std::cout << *easyfind(arr, 1) << std::endl; // exception thrown
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}
}