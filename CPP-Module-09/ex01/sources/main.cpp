/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:19:16 by mtigunit          #+#    #+#             */
/*   Updated: 2023/09/21 20:24:14 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: Wrong number of arguments!\n";
		return (1);
	}
	RPN	rpn;
	rpn.RPNcalculator(argv[1]);
	return 0;
}
