/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:02:18 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/11 08:41:55 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

int main( void )
{
	std::cout << CYAN << "== Default constructor check: Fixed a; ==" << RESET << std::endl;
	Fixed a;

	std::cout << CYAN << "== Int constructor check: Fixed const b( 10 ); ==" << RESET << std::endl;	
	Fixed const b( 10 );

	std::cout << CYAN << "== Float constructor check: Fixed const c( 42.42f ); ==" << RESET << std::endl;
	Fixed const c( 42.42f );
	
	std::cout << CYAN << "== Copy constructor check: Fixed const d( b ); ==" << RESET << std::endl;
	Fixed const d( b );

	std::cout << CYAN << "== Copy assignment operator check: a = Fixed( 1234.4321f ); ==" << RESET << std::endl;
	a = Fixed( 1234.4321f );

	std::cout << CYAN << "== Overload of the insertion («) operator check ==" << RESET << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << CYAN << "== toInt function check ==" << RESET << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
