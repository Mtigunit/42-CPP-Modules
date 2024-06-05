/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:18:05 by mtigunit          #+#    #+#             */
/*   Updated: 2023/07/23 13:17:18 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

/* ***************************************** */
/*          Orthodox Canonical Form          */
/* ***************************************** */

AForm::AForm()
	: _name("Form")
	, _signed(false)
	, _gradeToSign(MIN_GRADE)
	, _gradeToExecute(MIN_GRADE) {}

AForm::AForm(const AForm & Copy)
	: _name(Copy.getName())
	, _signed(Copy.getSigned())
	, _gradeToSign(Copy.getGradeToSign())
	, _gradeToExecute(Copy.getGradeToExecute()) {}

AForm&	AForm::operator=(const AForm& src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return (*this);
}

AForm::~AForm() {}

/* ***************************************** */
/*                  Getters                  */
/* ***************************************** */

const std::string	AForm::getName() const {
	return (_name);
}

bool	AForm::getSigned() const {
	return (_signed);
}

int	AForm::getGradeToSign() const {
	if (_gradeToSign < MAX_GRADE) {
		throw GradeTooHighException();
	}
	else if (_gradeToSign > MIN_GRADE) {
		throw GradeTooLowException();
	}
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const {
	if (_gradeToExecute < MAX_GRADE) {
		throw GradeTooHighException();
	}
	else if (_gradeToExecute > MIN_GRADE) {
		throw GradeTooLowException();
	}
	return (_gradeToExecute);
}


/* ***************************************** */
/*                   Other                   */
/* ***************************************** */

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute)
	: _name(name)
	, _signed(false)
	, _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute) {

    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE) {
        throw GradeTooHighException();
	} else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE) {
        throw GradeTooLowException();
	}
}

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign()) {
		this->_signed = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, AForm& AForm) {
	os	<< "Form informations: (" << "Form name: " << AForm.getName()
		<< ", Form grade to signe: " << AForm.getGradeToSign()
		<< ", Form grade to execute: " << AForm.getGradeToExecute() << ")";
	return (os);
}

/* ***************************************** */
/*           GradeTooHighException           */
/* ***************************************** */

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Form: Grade Too Hight");
}

/* ****************************************** */
/*            GradeTooLowException            */
/* ****************************************** */

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Form: Grade Too Low");
}
