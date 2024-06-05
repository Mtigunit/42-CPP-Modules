/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:03:37 by mtigunit          #+#    #+#             */
/*   Updated: 2023/07/31 08:51:48 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat	bc(0, "bureaucrat");
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "cannot creat the bureaucrat because " << e.what() << '\n';
	}
	
	try {
		Bureaucrat	bc(200, "bureaucrat");
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "cannot creat the bureaucrat because " << e.what() << '\n';
	}

	try {
		Bureaucrat	bureaucrat1(1, "bureaucrat");
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.gradeUp();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "cannot increment the grade because " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat	bureaucrat2(150, "bureaucrat");
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.gradeDown();
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "cannot decrement the grade because " << e.what() << std::endl;
	}
}
