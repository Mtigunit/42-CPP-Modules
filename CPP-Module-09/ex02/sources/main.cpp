/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:07:15 by mtigunit          #+#    #+#             */
/*   Updated: 2023/10/30 17:15:34 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool	isValidArgument(std::string str) {
	if (str.empty()) return (false);

	if (str[0] == '+' && str[1]) str[0] = '0';
	size_t first = str.find_first_not_of("0123456789");
	if (first != str.npos) return (false);

	if ((atol(str.c_str()) > INT_MAX || atol(str.c_str()) < 0)) {
		return (false);
	}
	return (true);
}

void	checkErrors(char** argv) {
	for (size_t i = 1; argv[i]; i++) {
		if (isValidArgument(argv[i]) == false) {
			std::cout << "Error: Invalid argument!\n";
			exit(1);
		}
	}
}

void	printBefor(char** argv) {
	for (size_t i = 1; argv[i]; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << "\n";
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Error: Not enough arguments.\n";
		return 1;
	}
	if (argc == 2 && isValidArgument(argv[1]) == true) {
		std::cout << "One element is already sorted!.\n";
		return 0;
	}

	checkErrors(argv);

	std::vector<int>	vecContainer;
	std::deque<int>		dequeContainer;

	std::cout << "std::vector => Before: ";
	printBefor(argv);
	std::cout << "std::deque => Before: ";
	printBefor(argv);
	std::cout << "\n";

	clock_t start = clock();
	mergeInsertionSortVec(argv, vecContainer);
	clock_t end = clock();
	double vecDuration = (end - start);

	start = clock();
	mergeInsertionSortDeque(argv, dequeContainer);
	end = clock();
	double dequeDuration = (end - start);

	std::cout << "std::vector => After: ";
	printContainer(vecContainer);
	std::cout << "std::deque => After: ";
	printContainer(dequeContainer);
	std::cout << "\n";

	std::cout << "Time to process a range of " << vecContainer.size() 
			  << " elements with std::vector: " << (double)vecDuration << " us\n";
	std::cout << "Time to process a range of " << dequeContainer.size()
	 		  << " elements with std::deque: " << (double)dequeDuration << " us\n";

	return 0;
}
