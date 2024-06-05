/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:06:07 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 15:48:05 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("presidential pardon", GRADE_TO_SIGN_PRESIDENTIAL, GRADE_TO_EXEC_PRESIDENTIAL) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& Copy) 
	: AForm(Copy) {
	*this = Copy;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* ***************************************** */
/*                  Getters                  */
/* ***************************************** */

std::string	PresidentialPardonForm::getTarget( void ) const {
	return (this->_target);
}

/* ****************************************** */
/*                   Others                   */
/* ****************************************** */

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("presidential pardon", GRADE_TO_SIGN_PRESIDENTIAL, GRADE_TO_EXEC_PRESIDENTIAL)
	, _target(target) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false) {
		throw GradeTooLowException();
	} else if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
