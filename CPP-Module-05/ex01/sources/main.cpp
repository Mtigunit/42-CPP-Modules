/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:03:37 by mtigunit          #+#    #+#             */
/*   Updated: 2023/07/31 08:50:59 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

int	main() {
	Bureaucrat	bureaucrat;
	Bureaucrat	bureaucrat2(1, "RealKing");
	Form		form;
	Form		form2("form2", 30, 50);

	std::cout << "============= about bureaucrats =============\n";
	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat2 << std::endl;

	std::cout << "\n\n============= about forms =============\n";
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n\n============= sign forms =============\n";
	bureaucrat.signForm(form);
	bureaucrat2.signForm(form2);
}