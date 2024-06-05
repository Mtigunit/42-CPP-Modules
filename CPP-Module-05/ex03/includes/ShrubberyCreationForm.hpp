/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:22:10 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 16:00:16 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define GRADE_TO_SIGN_SHRUBBERY 145
#define GRADE_TO_EXEC_SHRUBBERY 137

/* *************************************** */
/*       ShrubberyCreationForm class       */
/* *************************************** */

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& Copy);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);

		std::string	getTarget( void ) const;
		void	execute(Bureaucrat const & executor) const;
};
