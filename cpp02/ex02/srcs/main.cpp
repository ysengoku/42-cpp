/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:03:01 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/11 08:55:50 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

void	testComparison( void )
{
	std::cout << MAGENTA << "TEST - Comparison Operator" << RESET <<  std::endl;
	Fixed	a(5);
	Fixed	b(2.7f);
	Fixed	c(5.0f);

	std::cout << "a: " << a << std::endl << "b: " << b << std::endl << "c: " << c <<std::endl;
	std::cout << "(a > b) -> " << (a > b) << " / (a > c) -> " << (a > c)  << std::endl;
	std::cout << "(a < b) -> " << (a < b) << " / (a < c) -> " << (a < c) << std::endl;
	std::cout << "(a >= b) -> " << (a >= b) << " / (a >= c) -> " << (a >= c) << std::endl;
	std::cout << "(a <= b) -> " << (a <= b) << " / (a <= c) -> " << (a <= c) << std::endl;
	std::cout << "(a == b) -> " << (a == b) << " / (a == c) -> " << (a == c) << std::endl;
	std::cout << "(a != b) -> " << (a != b) << " / (a != c) -> " << (a != c)  << std::endl;
}

void	testArithmetic( void )
{
	std::cout << std::endl << MAGENTA << "TEST - Arithmetic Operator" << RESET << std::endl;
	Fixed	a(5);
	Fixed	b(2.7f);

	std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
	std::cout << (a + b) << " (a + b)" << std::endl;
	std::cout << (a - b) << " (a - b)" << std::endl;
	std::cout << (a * b) << " (a * b)" << std::endl;
	if (b != 0)
		std::cout << (a / b) << " (a / b)" << std::endl;
	else
		std::cout << "Division by 0 is not accepted." << std::endl;
}

void	testIncrementDecrement( void )
{
	std::cout << std::endl << MAGENTA << "TEST - Increment/Decrement Operator" << RESET << std::endl;
	Fixed	a(2.7f);
	Fixed	b(2.7f);

	std::cout << "(a) " << a << std::endl;
	std::cout << "(++a) " << ++a << std::endl;
	std::cout << "(a) " << a << std::endl;
	std::cout << "(a++) " << a++ << std::endl;
	std::cout << "(a) " << a << std::endl << std::endl;
	std::cout << "(b) " << b << std::endl;
	std::cout << "(--b) " << --b << std::endl;
	std::cout << "(b) " << b << std::endl;
	std::cout << "(b--) " << b-- << std::endl;
	std::cout << "(b) " << b << std::endl;
}

void	testMinMax( void )
{
	std::cout << std::endl << MAGENTA << "TEST - Max/Min" << RESET << std::endl;
	Fixed	a(5);
	Fixed	b(2.7f);

	std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
	std::cout << "Max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min: " << Fixed::min( a, b ) << std::endl;
}

int main( void )
{
	std::cout << CYAN << "======= Test mentionned in the subject  =======" << RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl;

	std::cout << CYAN << "========= My own tests  =========" << RESET << std::endl;
	testComparison();
	testArithmetic();
	testIncrementDecrement();
	testMinMax();
	return (0);
}
