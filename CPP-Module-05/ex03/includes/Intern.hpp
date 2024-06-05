/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:53:14 by mtigunit          #+#    #+#             */
/*   Updated: 2023/07/30 17:16:22 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/* ************************************** */
/*              Intern class              */
/* ************************************** */

class Intern {
	public:
		Intern();
		Intern(const Intern& copy);
		Intern&	operator=(const Intern& src);
		~Intern();

		AForm*	makeForm(std::string formName, std::string target) const;

		class InternException : std::exception {
			public:
				const char* what() const throw();
		};
};
