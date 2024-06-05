/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:53:26 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/24 11:20:28 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <algorithm>

template<typename T>
typename T::const_iterator	easyfind(const T& container, int toFind) {
	typename T::const_iterator it = find(container.begin(), container.end(), toFind);

	if (it == container.end()) {
		throw std::runtime_error("Element not found!");
	} else {
		return (it);
	}
}
