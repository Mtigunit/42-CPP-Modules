/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:10:17 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/20 14:54:11 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

void    myTest( void ) {
	Array<int> emptyArr;
	std::cout << emptyArr.size() << std::endl;
	
	Array<float> arr(1000);
	std::cout << arr.size() << std::endl;

	for (size_t i = 0; i < 1000; i++) {
		arr[i] = i + 0.5;
	}
	std::cout << "index 7 in arr: " << arr[7] << std::endl;
	Array<float> copy = arr;
	std::cout << "arr: " << &arr << " copy: " << &copy << std::endl;
	std::cout << "index 7 in copy: " << copy[7] << std::endl;
}

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "================== my test ==================" << std::endl;
	myTest();
	std::cout << "================== intra main ==================" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}