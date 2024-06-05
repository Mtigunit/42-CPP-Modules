/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:34 by mtigunit          #+#    #+#             */
/*   Updated: 2023/06/10 11:22:40 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "phoneBook.hpp"

int	main() {
	PhoneBook phonebook;
	std::string str;

	while (1) {
		std::getline(std::cin, str);
		if (str.empty()) {
			exit(0);
		}
		if (str == "ADD") {
			phonebook.addContact();
		} else if (str == "SEARCH") {
			phonebook.printContact();
		} else if (str == "EXIT") {
			break ;
		} else {
			std::cout << "Wrong option! Try again." << std::endl;
			continue ;
		}
	}
	return (0);
}
