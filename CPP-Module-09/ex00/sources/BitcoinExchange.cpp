/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:11:17 by mtigunit          #+#    #+#             */
/*   Updated: 2023/10/30 17:01:38 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

/* ******************************** */
/*         Helper Functions         */
/* ******************************** */

void	trimSpaces(std::string &str) {
    size_t end = str.find_last_not_of(" \t");
    if (end != std::string::npos) {
        str = str.substr(0, end + 1);
    }
    size_t start = str.find_first_not_of(" \t");
    if (start != std::string::npos) {
        str = str.substr(start);
    }
}

void	doExchange(std::map<std::string, float> &dataBase, std::string& date, float value) {
	std::map<std::string, float>::const_iterator it = dataBase.find(date);
	if (it == dataBase.end()) {
		it = dataBase.lower_bound(date) != dataBase.begin()
			? --dataBase.lower_bound(date) : dataBase.begin();
	}
	std::cout << date << " => " << value << " = "
			  << it->second * value << "\n";
}

bool	isValidDateFormat(const std::string& dateStr) {
	if (dateStr.length() != 10)
		return (false);
	if (dateStr[4] != '-' || dateStr[7] != '-')
		return (false);

	int year = std::atoi(dateStr.substr(0, 4).c_str());
	int month = std::atoi(dateStr.substr(5, 2).c_str());
	int day = std::atoi(dateStr.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	return (true);
}

bool	parceDate(std::string& dateStr) {
	if (!isValidDateFormat(dateStr)) {
		std::cout << "Error: Invalid date format!\n";
		return (true);
	}
	return (false);
}

bool	parceValue(std::string& valueStr) {
	size_t first = valueStr.find_first_not_of("0123456789.");
	if (first != valueStr.npos) {
		std::cout << "Error: Invalid value format!\n";
		return (true);
	}

	size_t firstP = valueStr.find_first_of('.');
	size_t lastP = valueStr.find_last_of('.');
	if (firstP != valueStr.npos
		&& (firstP != lastP || (!isdigit(valueStr[firstP - 1]) || !isdigit(valueStr[lastP + 1])))) {
		std::cout << "Error: Invalid value format!\n";
		return (true);
	}

	float value = atof(valueStr.c_str());
	if (value < 0) {
		std::cout << "Error: not a positive number.\n";
		return (true);
	} else if (value > 1000) {
		std::cout << "Error: too large a number.\n";
		return (true);
	}
	return (false);
}

bool	parceLines(std::string& date, std::string& value) {
	return (parceDate(date) || parceValue(value));
}

/* ******************************** */
/*        Orthodox Canonical        */
/* ******************************** */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src) {
		dataBase = src.dataBase;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/* ******************************** */
/*              Seters              */
/* ******************************** */

void	BitcoinExchange::setDataBase(std::map<std::string, float>& newDB) {
	dataBase = newDB;
}

/* ******************************** */
/*          Other Functions         */
/* ******************************** */

BitcoinExchange::BitcoinExchange(const char* dataBaseFile) {
	std::ifstream DB;
	DB.open(dataBaseFile);
	if (!DB.is_open()) {
		std::cout << "Error: Unable to open the database.\n";
		std::exit(1);
	}
	std::string	line, date;
	std::getline(DB, line);
	if (line != "date,exchange_rate") {
		std::cout << "Error: Invalid file format!\n";
		// std::exit(1);
	}
    while (std::getline(DB, line)) {
        std::istringstream ss(line);
        std::string token;
        
        if (std::getline(ss, token, ',')) {
            date = token;
        }
        if (std::getline(ss, token)) {
            dataBase[date] = std::atof(token.c_str());
        }
		// trimSpaces(token);
		// trimSpaces(date);
		if (token.empty() || date.empty()) {
			std::cout << "Error: Invalid file format!\n";
		}
    }
	DB.close();
}

void	BitcoinExchange::proccessExchange(const char* inputFile) {

	std::ifstream file;
    file.open(inputFile);
    if (!file.is_open()) {
        std::cout << "Error: could not open file.\n";
        std::exit(1);
    }

    std::string			line;
    std::getline(file, line);


	std::istringstream	iss(line);
	std::string			dateStr;
	std::string			valueStr;

	if (std::getline(iss, dateStr, '|') && std::getline(iss, valueStr)) {
		trimSpaces(dateStr);
		trimSpaces(valueStr);
		if (dateStr != "date" || valueStr != "value")
		    std::cout << "Error: Invalid file format!\n";
	} else {
		std::cout << "Error: Invalid file format!\n";
	}

    while (std::getline(file, line)) {
		std::istringstream	iss(line);
		std::getline(iss, dateStr, '|');
		std::getline(iss, valueStr);

		if (dateStr.empty() || valueStr.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		trimSpaces(dateStr);
		trimSpaces(valueStr);
		if (parceLines(dateStr, valueStr)) {
			continue ;
		}
		float value = atof(valueStr.c_str());
		doExchange(dataBase, dateStr, value);
    }

	file.close();
}
