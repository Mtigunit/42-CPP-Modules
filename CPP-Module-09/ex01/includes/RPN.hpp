/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:20:37 by mtigunit          #+#    #+#             */
/*   Updated: 2023/10/29 11:44:04 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
	private:
		std::stack<double>	opStack;
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& src);
		~RPN();

		void	RPNcalculator(const std::string& expression);
};
