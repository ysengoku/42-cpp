/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:36:55 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/13 11:44:29 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"
#include "Fixed.hpp"

void	testFromSubject(void) {
	std::cout << CYAN << "===== Tests from the subject =====" << RESET << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void	additionalTests(void) {
	std::cout << std::endl << CYAN << "===== My own tests =====" << RESET << std::endl; 
	{
		std::cout << "----- char -----" << std::endl;
		char a = 'A';
		char b = 'Z';
		std::cout << "BEFORE swap: a = " << a << " b = " << b << std::endl;
		::swap(a, b);
		std::cout << "AFTER swap:  a = " << a << " b = " << b << std::endl;
		std::cout << "min( " << a << ", " << b << " ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( " << a << ", " << b << " ) = " << ::max( a, b ) << std::endl;
	}
	{
		std::cout << std::endl << "----- double -----" << std::endl;
		double a = 1.5;
		double b = 4.2;
		std::cout << "BEFORE swap: a = " << a << " b = " << b << std::endl;
		::swap(a, b);
		std::cout << "AFTER swap:  a = " << a << " b = " << b << std::endl;
		std::cout << "min( " << a << ", " << b << " ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( " << a << ", " << b << " ) = " << ::max( a, b ) << std::endl;
	}
	{
		std::cout << std::endl << "----- float -----" << std::endl;
		float a = 1.5f;
		float b = 4.2f;
		std::cout << "BEFORE swap: a = " << a << " b = " << b << std::endl;
		::swap(a, b);
		std::cout << "AFTER swap:  a = " << a << " b = " << b << std::endl;
		std::cout << "min( " << a << ", " << b << " ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( " << a << ", " << b << " ) = " << ::max( a, b ) << std::endl;
	}
	{
		std::cout << std::endl << "----- bool -----" << std::endl;
		bool a = true;
		bool b = false;
		std::cout << "BEFORE swap: a = " << a << " b = " << b << std::endl;
		::swap(a, b);
		std::cout << "AFTER swap:  a = " << a << " b = " << b << std::endl;
		std::cout << "min( " << a << ", " << b << " ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( " << a << ", " << b << " ) = " << ::max( a, b ) << std::endl;
	}
	{
		std::cout << std::endl << "----- 'Fixed' class -----" << std::endl;
		Fixed a(1.2f);
		Fixed b(2.0f);
		std::cout << "BEFORE swap: a = " << a << " b = " << b << std::endl;
		::swap(a, b);
		std::cout << "AFTER swap:  a = " << a << " b = " << b << std::endl;
		std::cout << "min( " << a << ", " << b << " ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( " << a << ", " << b << " ) = " << ::max( a, b ) << std::endl;
	}
}

int main( void ) {
	testFromSubject();
	additionalTests();
	return 0;
}
