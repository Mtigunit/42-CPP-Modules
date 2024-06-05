/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:20:41 by mtigunit          #+#    #+#             */
/*   Updated: 2023/10/30 13:06:47 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) {
	*this = copy;
}

RPN&	RPN::operator=(const RPN& src) {
	if (this != &src) {
		opStack = src.opStack;
	}
	return (*this);
}

RPN::~RPN() {}

double performOperation(double operand1, double operand2, std::string operation) {
	if (operation == "+")
		return operand1 + operand2;
	else if (operation == "-")
		return operand1 - operand2;
	else if (operation == "*")
		return operand1 * operand2;
	else if (operation == "/") {
		if (operand2 == 0) {
			std::cout << "Error: Can not devide by zero!\n";
			exit(1);
		}
		return operand1 / operand2;
	}
	else {
		std::cout << "Error: Invalid RPN expression\n";
		exit(1);
	}
}

void RPN::RPNcalculator(const std::string& expression) {
    std::stack<double> operandStack;
    std::istringstream iss(expression);

    std::string token;
    while (iss >> token) {
        if ((token.length() == 1 && isdigit(token[0]))
			|| (token.length() == 2 && ((token[0] == '-' || token[0] == '+') && isdigit(token[1])))) {
            operandStack.push(atof(token.c_str()));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (operandStack.size() < 2) {
				std::cout << "Error: Invalid RPN expression\n";
				exit(1);
            }
            double num1 = operandStack.top();
            operandStack.pop();
            double num2 = operandStack.top();
            operandStack.pop();
            double result = performOperation(num2, num1, token);
            operandStack.push(result);
        } else {
			std::cout << "Error: Invalid RPN expression\n";
			exit(1);
		}
    }

    if (operandStack.size() != 1) {
		std::cout << "Error: Invalid RPN expression\n";
		exit(1);
    }

	std::cout << operandStack.top() << std::endl;
}
