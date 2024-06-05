/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:08:27 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/20 14:59:59 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T, typename F>
void	iter(T arrAddress, size_t arrLen, F callBack) {
	for (size_t i = 0; i < arrLen; i++) {
		callBack(arrAddress[i]);
	}
}
