/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:20:33 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/04 16:01:59 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("shrubbery creation", GRADE_TO_SIGN_SHRUBBERY, GRADE_TO_EXEC_SHRUBBERY) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& Copy)
	: AForm(Copy) {
	*this = Copy;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	if (this != &src) {
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* ***************************************** */
/*                  Getters                  */
/* ***************************************** */

std::string	ShrubberyCreationForm::getTarget( void ) const {
	return (this->_target);
}

/* ****************************************** */
/*                   Others                   */
/* ****************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("shrubbery creation", GRADE_TO_SIGN_SHRUBBERY, GRADE_TO_EXEC_SHRUBBERY)
	, _target(target) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false) {
		throw GradeTooLowException();
	} else if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::ofstream	outFile(_target + "_shrubbery");
	if (!outFile.is_open()) {
        std::cout << "Error creating/opening the file.\n";
		return ;
	}
	outFile <<	
				"                 ,@@@@,                               ,@@@,                      ccee88oo\n"
				"               ,@@@@@@@,                            ,@@@@@@@,                 C8O8O8Q8PoOb o8oo\n"
				"       ,,,.   ,@@@@@@/@@,  .oo8888o.        ,,,.   ,@@@@@@/@@,  .oo8888o.    dOB69QO8PdUOpugoO9bD\n"
				"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o  CgggbU8OU qOp qOdoUOdcb\n"
				"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'     6OuU  /p u gcoUodpP\n"
				"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'       \\\\\\//  /douUP\n"
				"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'         \\\\\\////\n"
				"   `&%\\ ` /%&'    |.|        \\ '|8'     `&%\\ ` /%&'    |.|        \\ '|8'            |||/\\\n"
				"       |o|        | |         | |           |o|        | |         | |              |||\\/\n"
				"       |.|        | |         | |           |.|        | |         | |              |||||\n"
				"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__\\_.....//||||\\....\n";
	outFile.close();
}
