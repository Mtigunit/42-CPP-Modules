/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:18:05 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 15:35:27 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/* ***************************************** */
/*          Orthodox Canonical Form          */
/* ***************************************** */

Form::Form()
	: _name("defaultForm"), _signed(false), _gradeToSign(MAX_GRADE), _gradeToExecute(MAX_GRADE) {}

Form::Form(const Form & Copy)
	: _name(Copy.getName()), _signed(Copy.getSigned()),
		_gradeToSign(Copy.getGradeToSign()), _gradeToExecute(Copy.getGradeToExecute()) {}

Form&	Form::operator=(const Form& src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return (*this);
}

Form::~Form() {}

/* ***************************************** */
/*                  Getters                  */
/* ***************************************** */

const std::string	Form::getName() const {
	return (_name);
}

bool	Form::getSigned() const {
	return (_signed);
}

int	Form::getGradeToSign() const {
	if (_gradeToSign < MAX_GRADE) {
		throw GradeTooHighException();
	}
	else if (_gradeToSign > MIN_GRADE) {
		throw GradeTooLowException();
	}
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const {
	if (_gradeToExecute < 0) {
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

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw GradeTooHighException();
    else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw GradeTooLowException();
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign()) {
		this->_signed = true;
	}
	else {
		throw GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, Form& form) {
	os	<< "--> Form informations: (" << "form name: " << form.getName()
		<< ", form grade to signe: " << form.getGradeToSign()
		<< ", form grade to execute: " << form.getGradeToExecute() << ")";
	return (os);
}

/* ***************************************** */
/*           GradeTooHighException           */
/* ***************************************** */

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form: Grade Too Hight");
}

/* ***************************************** */
/*           GradeTooLowException           */
/* ***************************************** */

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Form: Grade Too Low");
}
