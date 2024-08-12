/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:02:36 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/12 13:35:23 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void testEmptyArray(void) {
	std::cout << CYAN << "===== Test - Empty array =====" << RESET << std::endl; 
	int array[3];
	::iter(&array, 3, ::incrementOne<int>);
	std::cout << std::endl ;
}

void testInt(void) {
	std::cout << CYAN << "===== Test 1 - int/increment =====" << RESET << std::endl; 
	int array[] = {2, 15, -42, 0, 12345};
	size_t len = sizeof(array) / sizeof(int);
	std::cout << "BEFORE: ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";

	::iter(&array, len, ::incrementOne<int>);
	
	std::cout << std::endl << "AFTER:  ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl << std::endl;
}

void testDouble(void) {
	std::cout << CYAN << "===== Test 2 - double/increment =====" << RESET << std::endl; 
	double array[] = {2.5, 15.0, -42.9, 0.25, 12345.123};
	size_t len = sizeof(array) / sizeof(double);
	std::cout << "BEFORE: ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";

	::iter(&array, len, ::incrementOne<double>);
	
	std::cout << std::endl << "AFTER:  ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl << std::endl;
}

void testChar(void) {
	std::cout << CYAN << "===== Test 3 - char/increment =====" << RESET << std::endl; 
	char array[] = {'a', 'A', 'z', 'Z', 'k', 'D'};
	size_t len = sizeof(array) / sizeof(char);
	std::cout << "BEFORE: ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";

	::iter(&array, len, ::incrementOne<char>);
	
	std::cout << std::endl << "AFTER:  ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl << std::endl;
}

void toupperWrapper(char &c) {
	c = std::toupper(c, std::locale::classic());
}

void testChar2(void) {
	std::cout << CYAN << "===== Test 4 - char/toupper =====" << RESET << std::endl; 
	char array[] = {'a', 'A', 'z', 'Z', 'k', '*'};
	size_t len = sizeof(array) / sizeof(char);
	std::cout << "BEFORE: ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";

	::iter(&array, len, ::toupperWrapper);
	
	std::cout << std::endl << "AFTER:  ";
	for (size_t i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void writeA(size_t const& n) {
	for (size_t i = 0; i < n; i++)
		std::cout << 'A';
	std::cout << std::endl;
}

void testChar3(void) {
	std::cout << CYAN << "===== Test 5 - char/write =====" << RESET << std::endl; 
	size_t array[] = {2, 15, 0, 5, 20};
	size_t len = sizeof(array) / sizeof(size_t);
	::iter(&array, len, ::writeA);
	std::cout << std::endl;
}

int main(void) {
	testEmptyArray();
	testInt();
	testDouble();
	testChar();
	testChar2();
	testChar3();
	return 0;
}
