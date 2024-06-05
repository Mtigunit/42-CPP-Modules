/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:53:29 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/18 09:54:05 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define IS_CHAR 		0
#define IS_INT			1
#define IS_FLOAT 		2
#define IS_DOUBLE 		3
#define IS_IMPOSSIBLE	-1

/* ***************************************** */
/*           ScalarConverter class           */
/* ***************************************** */

class ScalarConverter {
	private:
		ScalarConverter();

		static std::string	_str;
		
	public:
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter&	operator=(const ScalarConverter& src);
		~ScalarConverter();

		ScalarConverter(std::string str);
		static void	convert(const std::string& str);
		static std::string	getStr();
		static void			printChar(const int flag);
		static void			printInt(const int flag);
		static void			printFloat(const int flag);
		static void			printDouble(const int flag);	
};
