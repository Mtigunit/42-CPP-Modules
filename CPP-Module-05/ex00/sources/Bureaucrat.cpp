/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:08:03 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 15:31:47 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/* ***************************************** */
/*          Orthodox Canonical Form          */
/* ***************************************** */

Bureaucrat::Bureaucrat() : _name("bureaucrat"), _grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(const Bureaucrat& Copy) {
	*this = Copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src) {
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

/* ***************************************** */
/*                  Getters                  */
/* ***************************************** */

const std::string	Bureaucrat::getName( void ) const {
	return (_name);
}

int	Bureaucrat::getGrade( void ) const {
	return (_grade);
}

/* ***************************************** */
/*                   Other                   */
/* ***************************************** */

Bureaucrat::Bureaucrat(int grade, const std::string name) : _name(name) {
	if (grade > MIN_GRADE) {
		throw GradeTooLowException();
	} else if (grade < MAX_GRADE) {
		throw GradeTooHighException();
	} else {
		_grade = grade;
	}
}

void	Bureaucrat::gradeUp() {
	_grade--;
	if (_grade < MAX_GRADE) {
		_grade++;
		throw GradeTooHighException();
	}
}

void	Bureaucrat::gradeDown() {
	_grade++;
	if (_grade > MIN_GRADE) {
		_grade--;
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

/* ***************************************** */
/*           GradeTooHighException           */
/* ***************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("bureaucrat: Grade Too High!");
}

/* ****************************************** */
/*            GradeTooLowException            */
/* ****************************************** */

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("bureaucrat: Grade Too Low!");
}
