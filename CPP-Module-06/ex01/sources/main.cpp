/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:40:19 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/18 10:01:26 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int	main() {
	Data* ptr = new Data(5);
	uintptr_t	uiptr = Serializer::serialize(ptr);
	Data* ptr2 = Serializer::deserialize(uiptr);
	std::cout << "uiptr: " << uiptr << "\nptr2: " << ptr2 << std::endl;
	std::cout << "Value: " << ptr2->getData() << std::endl;

	uintptr_t	uiptr2 = Serializer::serialize(ptr2);
	ptr = Serializer::deserialize(uiptr2);
	std::cout << "\nuiptr2: " << uiptr << "\nptr: " << ptr << std::endl;
	std::cout << "Value: " << ptr->getData() << std::endl;
	delete ptr;
	return (0);
}