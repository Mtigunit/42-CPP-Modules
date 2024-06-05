/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:34:11 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 15:53:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <iostream>
#include <exception>

/* ******************************************** */
/*               Bureaucrat class               */
/* ******************************************** */

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& Copy);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		Bureaucrat(int grade, const std::string name);

		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void				gradeUp();
		void				gradeDown();

		void				signForm(AForm& form) ;
		void				executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat& bureaucrat);
