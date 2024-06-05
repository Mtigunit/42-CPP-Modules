/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:03:07 by mtigunit          #+#    #+#             */
/*   Updated: 2023/07/30 16:23:19 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

/* ******************************************** */
/*                  Form class                  */
/* ******************************************** */

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const Form& Copy);
		~Form();
		Form&				operator=(const Form& src);

		Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
		const std::string	getName() const ;
		bool				getSigned() const ;
		int					getGradeToSign() const ;
		int					getGradeToExecute() const ;
		void				beSigned(Bureaucrat& bureaucrat);

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&				operator<<(std::ostream& os, Form& form);