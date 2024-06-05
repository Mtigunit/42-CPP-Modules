/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:41 by mtigunit          #+#    #+#             */
/*   Updated: 2023/07/19 18:10:37 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include <iostream>
#include <string>

static int	checkIndex(std::string tmp) {
	for (size_t i = tmp.length() - 1; std::iswspace(tmp[i]); i--) {
		tmp[i] = 0;
	}
	for (int i = 0; tmp[i]; i++) {
		if (!(tmp[i] <= '7' && tmp[i] >= '0'))
			return (-1);
	}
	return (std::atoi(tmp.c_str()));
}

static void printStr(const char *str) {
	for (int i = 0; i < 10; i++) {
		if (i == 9 && str[i])
			std::cout << '.';
		else if (i < 10 && str[i])
			std::cout << (char)str[i];
		else
			std::cout << ' ';
	}
	std::cout << " | ";
}

void	PhoneBook::printContact() {
	std::cout << "Index | First Name | Last Name  | Nickname   |\n";
	std::cout << "----------------------------------------------\n";
	for (std::size_t i = 0; i < 8; i++) {
		std::cout << i + 1 << "     | ";
		std::string str = contacts[i].getFirstName();
		printStr(str.c_str());
		str = contacts[i].getLastName();
		printStr(str.c_str());
		str = contacts[i].getNickName();
		printStr(str.c_str());
        std::cout << "\n";
    }
	std::cout << "----------------------------------------------\n";
	std::cout << "index: ";
	std::string tmp;
	std::getline(std::cin >> std::ws, tmp);
	if (tmp.empty()) {
		exit(0);
	}
	int index = checkIndex(tmp);
	while (index < 0) {
		std::cout << "Invalid index." << std::endl;
		std::cout << "index: ";
		std::getline(std::cin >> std::ws, tmp);
		if (tmp.empty()) {
			exit(0);
		}
		index = checkIndex(tmp);
	}
	if (index >= 1 && index <= 8) {
		if (this->contacts[index + 1].getFirstName().empty()) {
			std::cout << "empty!" << std::endl;
			return ;
		}
		std::cout << "first name: " << this->contacts[index + 1].getFirstName()<< std::endl;
		std::cout << "last name: " << this->contacts[index + 1].getLastName() << std::endl;
		std::cout << "nickname: " << this->contacts[index + 1].getNickName() << std::endl;
		std::cout << "phone number: " << this->contacts[index + 1].getPhoneNumber() << std::endl;
		std::cout << "darkest secret: " << this->contacts[index + 1].getDarkestSecret() << std::endl;
	} else {
		std::cout << "Invalid index." << std::endl;
	}
}

static bool	isValidPhoneNumber(std::string str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; str[i]; i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '(' 
			|| str[i] == ')' || str[i] == ' ' || std::isdigit(str[i]))
			continue ;
		return (false);
	}
	return (true);
}

void	PhoneBook::addContact() {
	static int index = 0;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	if (index >= 8)
		index = 0;
	std::cout << "first name: ";
	std::getline(std::cin >> std::ws, firstName);
	if (firstName.empty()) {
		exit(0);
	}
	this->contacts[index].setFirstName(firstName);

	std::cout << "last name: ";
	std::getline(std::cin >> std::ws, lastName);
	if (lastName.empty()) {
		exit(0);
	}
	this->contacts[index].setLastName(lastName);

	std::cout << "nickname: ";
	std::getline(std::cin >> std::ws, nickName);
	if (nickName.empty()) {
		exit(0);
	}
	this->contacts[index].setNickName(nickName);

	std::cout << "phone number: ";
	std::getline(std::cin >> std::ws, phoneNumber);
	if (phoneNumber.empty()) {
		exit(0);
	}
	while (!isValidPhoneNumber(phoneNumber)) {
		std::cout << "Invalid character!" << std::endl;
		std::cout << "phone number: ";
		std::getline(std::cin >> std::ws, phoneNumber);
		if (phoneNumber.empty()) {
			exit(0);
		}
	}
	this->contacts[index].setPhoneNumber(phoneNumber);

	std::cout << "darkest secret: ";
	std::getline(std::cin >> std::ws, darkestSecret);
	if (darkestSecret.empty()) {
		exit(0);
	}
	this->contacts[index].setDarkestSecret(darkestSecret);
	this->contacts[index].setIndex(index);
	index++;
}
