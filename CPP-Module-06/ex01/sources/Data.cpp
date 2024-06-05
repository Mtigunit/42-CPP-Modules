/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:37:25 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/16 10:55:31 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data() {}

Data::Data(int data) : _data(data) {}

Data::Data(const Data& copy) {
	(void)copy;
}

Data&	Data::operator=(const Data& src) {
	(void)src;
	return (*this);
}

int	Data::getData( void ) const {
	return (_data);
}

Data::~Data() {}
