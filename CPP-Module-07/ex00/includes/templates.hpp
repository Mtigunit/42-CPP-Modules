/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:18 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/20 13:06:50 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename Tswap>
void	swap(Tswap &x, Tswap &y) {
	Tswap temp = x;
	x = y;
	y = temp;
}

template <typename Tmin>
Tmin	min(Tmin a, Tmin b) {
	return ((a < b) ? a : b);
}

template <typename Tmax>
Tmax	max(Tmax a, Tmax b) {
	return ((a > b) ? a : b);
}
