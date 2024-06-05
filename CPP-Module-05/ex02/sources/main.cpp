/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:03:37 by mtigunit          #+#    #+#             */
/*   Updated: 2023/07/31 08:48:21 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat	bureaucrat1(150, "Somebody");
	Bureaucrat	bureaucrat2(1, "King");
	Bureaucrat	bureaucrat3(15, "President");
	AForm		*form = new ShrubberyCreationForm("scf");
	AForm		*form2 = new RobotomyRequestForm("rrf");
	AForm		*form3 = new PresidentialPardonForm("ppf");

	std::cout << "======== bureaucrat1 =========\n";
	std::cout << *form << std::endl;
	std::cout << bureaucrat1 << std::endl;
	std::cout << "\n\n======== bureaucrat1: sign forms =========\n";
	bureaucrat1.signForm(*form);
	bureaucrat1.signForm(*form2);
	bureaucrat1.signForm(*form3);
	std::cout << "\n\n======== bureaucrat1: execute forms =========\n";
	bureaucrat1.executeForm(*form);
	bureaucrat1.executeForm(*form2);
	bureaucrat1.executeForm(*form3);

	std::cout << "\n\n";

	std::cout << "\n\n======== bureaucrat2 =========\n";
	std::cout << bureaucrat2 << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << "\n\n======== bureaucrat2: sign forms =========\n";
	bureaucrat2.signForm(*form);
	bureaucrat2.signForm(*form2);
	bureaucrat2.signForm(*form3);
	std::cout << "\n\n======== bureaucrat2: execute forms =========\n";
	bureaucrat2.executeForm(*form);
	bureaucrat2.executeForm(*form2);
	bureaucrat2.executeForm(*form3);

	std::cout << "\n\n";

	std::cout << "\n\n======== bureaucrat3 =========\n";
	std::cout << bureaucrat3 << std::endl;
	std::cout << *form3 << std::endl;
	std::cout << "\n\n======== bureaucrat3: sign forms =========\n";
	bureaucrat3.signForm(*form);
	bureaucrat3.signForm(*form2);
	bureaucrat3.signForm(*form3);
	std::cout << "\n\n======== bureaucrat3: execute forms =========\n";
	bureaucrat3.executeForm(*form);
	bureaucrat3.executeForm(*form2);
	bureaucrat3.executeForm(*form3);

	delete form;
	delete form2;
	delete form3;
}