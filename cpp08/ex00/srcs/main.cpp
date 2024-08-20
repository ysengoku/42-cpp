/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:26:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/20 08:38:34 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

void listTest(int to_find1, int to_find2) {
	std::cout << std::endl << BGCYAN << " List Test " << RESET << std::endl;
	std::list< int > test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(42);
	test.push_back(4);
	test.push_front(5);
	std::cout << "List: ";
	for (std::list< int >::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << YELLOW << ">>> Searching " << to_find2 << "....." << RESET << std::endl;
	try
	{
		std::cout << easyfind(test, to_find1) << " has been found." << std::endl;
	}
	catch (NoOccurrenceException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << YELLOW << ">>> Searching " << to_find2 << "....." << RESET << std::endl;
	try
	{
		std::cout << easyfind(test, to_find2) << " has been found." << std::endl;
	}
	catch (NoOccurrenceException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void vectorTest(int to_find1, int to_find2) {
	std::cout << std::endl << BGCYAN << " Vector Test " << RESET << std::endl;
	std::vector< int > test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	std::cout << "Vector: ";
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i) << " ";
	std::cout << std::endl;

	std::cout << YELLOW << ">>> Searching " << to_find1 << "....." << RESET << std::endl;
	try
	{
		std::cout << easyfind(test, to_find1) << " has been found." << std::endl;
	}
	catch (NoOccurrenceException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << YELLOW << ">>> Searching " << to_find2 << "....." << RESET << std::endl;
	try
	{
		std::cout << easyfind(test, to_find2) << " has been found." << std::endl;
	}
	catch (NoOccurrenceException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main(void) {
	int to_find1 = 42;
	int to_find2 = 3;

	listTest(to_find1, to_find2);
	vectorTest(to_find1, to_find2);
	return (0);
}
