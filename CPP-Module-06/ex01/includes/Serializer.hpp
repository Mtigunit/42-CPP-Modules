/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:26:10 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/17 12:26:10 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"

/* **************************************** */
/*             Serializer class             */
/* **************************************** */

class Serializer {
	private:
		Serializer();
	public:
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& src);
		~Serializer();

		static uintptr_t	serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
};
