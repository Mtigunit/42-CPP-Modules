/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:18:37 by mtigunit          #+#    #+#             */
/*   Updated: 2023/07/31 08:24:15 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

/* ******************************************** */
/*                  Form class                  */
/* ******************************************** */

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(const AForm& Copy);
		AForm&				operator=(const AForm& src);
		virtual ~AForm();

		AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, AForm& form);