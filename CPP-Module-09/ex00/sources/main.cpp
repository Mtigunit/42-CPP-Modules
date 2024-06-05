/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:45:15 by mtigunit          #+#    #+#             */
/*   Updated: 2023/10/30 08:53:04 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#define DATA_BASE "data.csv"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file.\n";
		std::exit(1);
	}

	BitcoinExchange b(DATA_BASE);
	b.proccessExchange(argv[1]);
}
