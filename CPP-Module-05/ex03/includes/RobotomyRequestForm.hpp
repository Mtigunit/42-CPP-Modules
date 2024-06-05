/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:21:24 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 16:00:29 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define GRADE_TO_SIGN_ROBOTOMY 72
#define GRADE_TO_EXEC_ROBOTOMY 45

/* *************************************** */
/*        RobotomyRequestForm class        */
/* *************************************** */

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& Copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();
	
		RobotomyRequestForm(std::string target);

		std::string	getTarget( void ) const;
		void		execute(Bureaucrat const & executor) const;
};
