/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:11:14 by mtigunit          #+#    #+#             */
/*   Updated: 2023/09/21 20:24:30 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

/* ********************************* */
/*       BitcoinExchange class       */
/* ********************************* */

class BitcoinExchange {
	private:
		std::map<std::string, float> dataBase;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		BitcoinExchange(const char* dataBaseFile);
		void	proccessExchange(const char* inputFile);
		void	setDataBase(std::map<std::string, float>& newDB);
};
