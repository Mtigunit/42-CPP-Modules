/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:30:54 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 16:00:43 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define GRADE_TO_SIGN_PRESIDENTIAL 25
#define GRADE_TO_EXEC_PRESIDENTIAL 5

/* **************************************** */
/*       PresidentialPardonForm class       */
/* **************************************** */

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& Copy);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();
	
		PresidentialPardonForm(std::string target);
	
		std::string	getTarget( void ) const;
		void	execute(Bureaucrat const & executor) const;
};
