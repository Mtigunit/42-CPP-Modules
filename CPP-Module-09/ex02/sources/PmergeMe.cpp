/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:12:04 by mtigunit          #+#    #+#             */
/*   Updated: 2023/10/30 14:12:59 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ********************************* vector ********************************* */

static void	creatPairs(std::vector<std::pair<int, int> >& pairs, char** argv, int& struggler) {
	int	count = 0;
	for (int i = 1; argv[i]; count++, i += 2) {
		if (argv[i + 1] == NULL) {
			struggler = atoi(argv[i]);
			break ;
		}
		int	first = atoi(argv[i]);
		int	second = atoi(argv[i + 1]);
		if (first > second) {
			pairs.push_back(std::make_pair(first, second));
		} else {
			pairs.push_back(std::make_pair(second, first));
		}
	}
	std::sort(pairs.begin(), pairs.end());
}

static void	creatMainChainAndPend(std::vector<std::pair<int, int> >& pairs,
	std::vector<int>& mainChain, std::vector<int>& pend) {
	mainChain.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
}

static int binarySearchIndex(const std::vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return mid; // Element already exists at this index
		} else if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	// If the target is not found, 'left' will point to the index where it should be inserted
	return left;
}

static int	jacobnumber(int i)
{
	return ((i == 0 || i == 1) ? i : jacobnumber(i - 1) + 2 * jacobnumber(i - 2));
}

void	mergeInsertionSortVec(char** argv, std::vector<int>& mainChain) {
	std::vector<std::pair<int, int>	> pairs;
	int	struggler = -1;
	creatPairs(pairs, argv, struggler);
	std::vector<int> PendingChain;
	creatMainChainAndPend(pairs, mainChain, PendingChain);
	int jacob = 0;
	int save;
	int i = 1;

	while (jacob < (int)PendingChain.size()) {
		save = jacob;
		jacob = jacobnumber(i);
		for (int j = jacob; j > save; j--) {
			if (j < (int)PendingChain.size()) {
				int index = binarySearchIndex(mainChain, PendingChain[j]);
				mainChain.insert(mainChain.begin() + index, PendingChain[j]);
			}
		}
		i++;
	}
	if (struggler >= 0) {
		int index = binarySearchIndex(mainChain, struggler);
		mainChain.insert(mainChain.begin() + index, struggler);
	}
	// std::cout << std::is_sorted(mainChain.begin(), mainChain.end());
}

/* ********************************** deque ********************************** */

static void	creatPairsDeque(std::deque<std::pair<int, int> >& pairs, char** argv, int& struggler) {
	int	count = 0;
	for (int i = 1; argv[i]; count++, i += 2) {
		if (argv[i + 1] == NULL) {
			struggler = atoi(argv[i]);
			break ;
		}
		int	first = atoi(argv[i]);
		int	second = atoi(argv[i + 1]);
		if (first > second) {
			pairs.push_back(std::make_pair(first, second));
		} else {
			pairs.push_back(std::make_pair(second, first));
		}
	}
	std::sort(pairs.begin(), pairs.end());
}

static void	creatMainChainAndPendDeque(std::deque<std::pair<int, int> >& pairs,
	std::deque<int>& mainChain, std::deque<int>& pend) {
	mainChain.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
}


static int	binarySearchIndexDeque(const std::deque<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return mid; // Element already exists at this index
		} else if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	// If the target is not found, 'left' will point to the index where it should be inserted
	return left;
}

void	mergeInsertionSortDeque(char** argv, std::deque<int>& mainChain) {
	std::deque<std::pair<int, int>	> pairs;
	int	struggler = -1;
	creatPairsDeque(pairs, argv, struggler);
	std::deque<int> pend;
	creatMainChainAndPendDeque(pairs, mainChain, pend);
	size_t jacob = 0;
	int save;
	size_t i = 1;

	while (jacob < pend.size()) {
		save = jacob;
		jacob = jacobnumber(i);
		for (int j = jacob; j > save; j--) {
			if (j < (int)pend.size()) {
				int index = binarySearchIndexDeque(mainChain, pend[j]);
				mainChain.insert(mainChain.begin() + index, pend[j]);
			}
		}
		i++;
	}
	if (struggler >= 0) {
		int index = binarySearchIndexDeque(mainChain, struggler);
		mainChain.insert(mainChain.begin() + index, struggler);
	}
	// std::cout << std::is_sorted(mainChain.begin(), mainChain.end());
}
