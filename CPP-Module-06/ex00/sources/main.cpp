/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:40:45 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/18 09:31:33 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <sstream>

std::string ft_trimWhitespace(const std::string &input);

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(ft_trimWhitespace(static_cast<std::string>(argv[1])));
	return (0);
}
