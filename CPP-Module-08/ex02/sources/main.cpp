/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:10:36 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/24 11:59:14 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

void	myTest() {
	MutantStack<std::string> strs1;
	MutantStack<std::string> strs2;

	strs1.push("hello_00");
	strs1.push("hello_01");
	strs1.push("hello_02");
	strs1.push("hello_03");
	strs1.push("hello_04");

	strs2 = strs1;

	std::cout << "iterator: " << std::endl; 
	MutantStack<std::string>::iterator it = strs1.begin();
	for (; it != strs1.end(); it++) {
		*it += "_modified";
		std::cout << *it << std::endl; 
	}

	std::cout << "const iterator: " << std::endl; 
	MutantStack<std::string>::const_iterator it2 = strs2.begin();
	for (; it2 != strs2.end(); it2++) {
		// *it2 += "_modified"; //can't be modified
		std::cout << *it2 << std::endl; 
	}
	
}

void	subjectTest()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

int	main()
{
	std::cout << "==== My tçest ====\n";
	myTest();
	std::cout << "\n==== subject test ====\n";
	subjectTest();
	std::cout << "\n==== List instead of MutantStack ====\n";
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
	return 0;
}
