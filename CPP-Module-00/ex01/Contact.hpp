/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:31 by mtigunit          #+#    #+#             */
/*   Updated: 2023/06/10 07:35:07 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

#ifndef CONTACT_HPP
# define CONTACT_HPP

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Contact{
	private:
		int			 index;
		std::string phoneNumber;
		std::string firstName;
		std::string lastName;
		std::string	nickName;
		std::string darkestSecret;

	public:
		int			getIndex();
		void		setIndex(int index);
		std::string getDarkestSecret();
		void		setDarkestSecret(std::string darkestSecret);
		std::string getPhoneNumber();
		void		setPhoneNumber(std::string phoneNumber);
		std::string getFirstName();
		void		setFirstName(std::string firstName);
		std::string	getLastName();
		void		setLastName(std::string phoneNumber);
		std::string	getNickName();
		void		setNickName(std::string nickName);
};

#endif /* CONTACT_HPP */