/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:53:37 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/18 09:52:43 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <cmath>

std::string	ScalarConverter::_str;

/* ***************************************** */
/*          Orthodox Canonical Form          */
/* ***************************************** */

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {(void)src; return(*this);}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {(void)copy;}

/* ************************************ */
/*                Geters                */
/* ************************************ */

std::string	ScalarConverter::getStr() {return (_str);}

/* ************************************* */
/*            Other functions            */
/* ************************************* */

ScalarConverter::ScalarConverter(std::string str) {
	ScalarConverter::_str = str;
}

void	ScalarConverter::convert(const std::string& str) {
	ScalarConverter::_str = str;
	size_t	i = (_str[0] == '-' || _str[0] == '+') ? 1 : 0;
	int	flag = IS_IMPOSSIBLE;
	for (; i < _str.length(); i++) {
		while (isdigit(_str[i])) {i++;}
		while (std::iswspace(_str[i])) {i++;}
		if (std::iswspace(_str[i - 1]) && _str[i]) {flag = IS_IMPOSSIBLE; break ;}
		if (!str[i]) {
			flag = IS_INT;
			break ;
		}

		if (isprint(_str[0]) && !_str[1]) {
			flag = IS_CHAR;
			break ;
		}
		if (_str[i] == '.') {
			if (_str[++i] && !isdigit(_str[i]) && _str[i] != 'f') {
				break ;
			}
			while (isdigit(_str[i])) {i++;}
			if (!_str[i]) {
				flag = IS_DOUBLE;
				break ;
			}
		}
		if (_str[i] == 'f' && !_str[i + 1]) {
			flag = IS_FLOAT;
			break ;
		}
		if (isalpha(_str[i]) && (isdigit(_str[i - 1]) || !_str[i + 1] || isdigit(_str[i + 1]))) {
			flag = IS_IMPOSSIBLE;
			break ;
		}
	}
	printChar(flag);
	printInt(flag);
	printFloat(flag);
	printDouble(flag);
}

void	ScalarConverter::printChar(const int flag) {
	long long c = _str[0];
	if (flag != IS_CHAR)
		c = std::atoll(_str.c_str());
	if (flag == IS_IMPOSSIBLE
		|| _str == "nan" || _str == "nanf"
		|| _str == "+inf" || _str == "-inf"
		|| c > 127 || c < 0) {
		std::cout << "char: impossible\n";
		return ;
	} else if (((c < 8 || c > 13) && c < 32)) {
		std::cout << "char: Non displayable\n";
		return ;
	}
	std::cout << "char: \'" << static_cast<char>(c) << "\'\n";
}

void	ScalarConverter::printInt(const int flag) {
	long long num = std::atoll(_str.c_str());
	if (flag == IS_IMPOSSIBLE
		|| _str == "nan" || _str == "nanf"
		|| _str == "+inf" || _str == "-inf"
		|| (num > INT_MAX || num < INT_MIN)) {
		std::cout << "int: impossible\n";
	} else if (flag == IS_INT || flag == IS_FLOAT || flag == IS_DOUBLE) {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	} else if (flag == IS_CHAR) {
		std::cout << "int: " << static_cast<int>(_str[0]) << std::endl;
	}
}

void	ScalarConverter::printFloat(const int flag) {
	float	num = std::atof(_str.c_str());
	if (flag == IS_CHAR) {
		std::cout << "float: " << static_cast<float>(_str[0]) << ".0f" << std::endl;
	} else if (flag == IS_IMPOSSIBLE && _str != "nan" && _str != "nanf") {
		std::cout << "float: impossible\n";
	} else if (_str == "nanf" || _str == "nan") {
		std::cout << "float: nanf\n";
	} else {
		std::cout << "float: " << static_cast<float>(num)
				  << (num == static_cast<float>(static_cast<int>(num)) ? ".0f" : "f")
				  << std::endl;
	}
}

void	ScalarConverter::printDouble(const int flag) {
	double	num = std::atof(_str.c_str());
	if (flag == IS_CHAR) {
		std::cout << "double: " << static_cast<double>(_str[0]) << ".0" << std::endl;
	} else if (flag == IS_IMPOSSIBLE && _str != "nan" && _str != "nanf") {
		std::cout << "double: impossible\n";
	} else if (_str == "nanf" || _str == "nan") {
		std::cout << "double: nan\n";
	} else {
		std::cout << "double: " << static_cast<double>(num)
				  << (num == static_cast<double>(static_cast<int>(num)) ? ".0" : "")
				  << std::endl;
	}
}

std::string ft_trimWhitespace(const std::string &input) {
	size_t start = 0;
	size_t end = input.length();

	while (start < end && std::iswspace(input[start])) {
		start++;
	}
	while (end > start && std::iswspace(input[end - 1])) {
		end--;
	}
	return input.substr(start, end - start);
}
