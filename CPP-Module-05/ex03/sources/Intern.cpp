/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:03:58 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 15:27:00 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

/* ***************************************** */
/*          Orthodox Canonical Form          */
/* ***************************************** */

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern&	Intern::operator=(const Intern& src) {
	(void)src;
	return (*this);
}

Intern::~Intern() {}

/* ***************************************** */
/*                   Other                   */
/* ***************************************** */

AForm* newShrubbery(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm* newRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm* newPresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string formName, std::string target) const {
	typedef AForm*	(*funcPtr)(std::string);
	funcPtr	form[] = {&newShrubbery, &newRobotomy, &newPresidential};

	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (size_t i = 0; i < 3; i++) {
		if (formName == names[i]) {
			return ((form[i])(target));
		}
	}
	throw InternException();
}

/* *************************************** */
/*             InternException             */
/* *************************************** */

const char* Intern::InternException::what() const throw() {
	return ("InternException: Unknown form!");
}
