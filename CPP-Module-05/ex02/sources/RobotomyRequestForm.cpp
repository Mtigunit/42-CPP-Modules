/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:19:11 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 15:46:35 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("robotomy request", GRADE_TO_SIGN_ROBOTOMY, GRADE_TO_EXEC_ROBOTOMY) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& Copy)
	: AForm(Copy) {
	*this = Copy;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* ***************************************** */
/*                  Getters                  */
/* ***************************************** */

std::string	RobotomyRequestForm::getTarget( void ) const {
	return (this->_target);
}

/* ****************************************** */
/*                   Others                   */
/* ****************************************** */

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("robotomy request", GRADE_TO_SIGN_ROBOTOMY, GRADE_TO_EXEC_ROBOTOMY)
	, _target(target) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false) {
		throw GradeTooLowException();
	} else if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	if (std::rand() % 2 == 1) {
		std::cout << "RRRrrrRRRrrrRRRrrr...! ";
		std::cout << _target << " has been robotomized successfully.\n";
	} else {
		std::cout << _target << " failed\n";
	}
}
