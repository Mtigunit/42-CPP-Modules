/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:25 by mtigunit          #+#    #+#             */
/*   Updated: 2023/06/10 07:13:34 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	Contact::getIndex() {
	return (this->index);
}

void	Contact::setIndex(int index) {
	this->index = index;
}

std::string Contact::getFirstName() {
	return (this->firstName);
}

void	Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

std::string	Contact::getLastName() {
	return (this->lastName);
}

void	Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

std::string	Contact::getNickName() {
	return (this->nickName);
}

void	Contact::setNickName(std::string nickName) {
	this->nickName = nickName;
}

std::string	Contact::getDarkestSecret() {
	return (this->darkestSecret);
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getPhoneNumber() {
	return (this->phoneNumber);
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}
