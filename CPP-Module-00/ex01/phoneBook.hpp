/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:44 by mtigunit          #+#    #+#             */
/*   Updated: 2023/06/10 07:31:20 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// ************************************************************************** //
//                             PhoneBook Class                                //
// ************************************************************************** //

class PhoneBook {
	private:
		Contact contacts[8];
	public:
		void	printContact();
		void	addContact();
};

#endif /* PHONEBOOK_HPP */