/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:45:18 by mtigunit          #+#    #+#             */
/*   Updated: 2023/09/21 20:23:29 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void	mergeInsertionSortDeque(char** argv, std::deque<int>& mainChain);
void	mergeInsertionSortVec(char** argv, std::vector<int>& mainChain);

template <typename Container>
void printContainer(const Container& container) {
	typename Container::const_iterator it;
	for (it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
