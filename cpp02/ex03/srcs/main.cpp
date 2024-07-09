/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:03:57 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 11:03:59 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "Point.hpp"

#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

extern bool bsp( Point const a, Point const b, Point const c, Point const point);

void	test1( void )
{
	std::cout << CYAN << "====== TEST1 ======" << RESET << std::endl;
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);
	Point point(1, 1);

	std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl \
	<< "b(" << b.getX() << ", " << b.getY() << ")" << std::endl \
	<< "c(" << c.getX() << ", " << c.getY() << ")" << std::endl \
	<< "point(" << point.getX() << ", " << point.getY() << ")" << std::endl \
	<< "Resultat: " << bsp(a, b, c, point) << std::endl;
}

void	test2( void )
{
    std::cout << CYAN << "====== TEST2 ======" << RESET << std::endl;
    Point a(0.0, 0.0);
    Point b(4.5, 0.0);
    Point c(0.0, 4.5);
    Point point(2.2, 1.1);

    std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl \
    << "b(" << b.getX() << ", " << b.getY() << ")" << std::endl \
    << "c(" << c.getX() << ", " << c.getY() << ")" << std::endl \
    << "point(" << point.getX() << ", " << point.getY() << ")" << std::endl \
    << "Result: " << bsp(a, b, c, point) << std::endl;
}

void	test3( void )
{
    std::cout << CYAN << "====== TEST3 ======" << RESET << std::endl;
    Point a(1.5, 1.5);
    Point b(5.5, 1.5);
    Point c(1.5, 4.5);
    Point point(2.5, 2.5);

    std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl \
    << "b(" << b.getX() << ", " << b.getY() << ")" << std::endl \
    << "c(" << c.getX() << ", " << c.getY() << ")" << std::endl \
    << "point(" << point.getX() << ", " << point.getY() << ")" << std::endl \
    << "Result: " << bsp(a, b, c, point) << std::endl;
}

void	test4( void )
{
	std::cout << CYAN << "====== TEST4 ======" << RESET << std::endl;
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);
	Point point(8, 9);

	std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl \
	<< "b(" << b.getX() << ", " << b.getY() << ")" << std::endl \
	<< "c(" << c.getX() << ", " << c.getY() << ")" << std::endl \
	<< "point(" << point.getX() << ", " << point.getY() << ")" << std::endl \
	<< "Resultat: " << bsp(a, b, c, point) << std::endl;
}

void	test5( void )
{
    std::cout << CYAN << "====== TEST5 ======" << RESET << std::endl;
    Point a(1.0, 1.0);
    Point b(3.0, 1.0);
    Point c(2.0, 4.0);
    Point point(2.0, 0.5);

    std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl \
    << "b(" << b.getX() << ", " << b.getY() << ")" << std::endl \
    << "c(" << c.getX() << ", " << c.getY() << ")" << std::endl \
    << "point(" << point.getX() << ", " << point.getY() << ")" << std::endl \
    << "Result: " << bsp(a, b, c, point) << std::endl;
}

void	test6( void )
{
	std::cout << CYAN << "====== TEST6 ======" << RESET << std::endl;
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);
	Point point(2, 2);

	std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl \
	<< "b(" << b.getX() << ", " << b.getY() << ")" << std::endl \
	<< "c(" << c.getX() << ", " << c.getY() << ")" << std::endl \
	<< "point(" << point.getX() << ", " << point.getY() << ")" << std::endl \
	<< "Resultat: " << bsp(a, b, c, point) << std::endl;
}

void	test7( void )
{
    std::cout << CYAN << "====== TEST7 ======" << RESET << std::endl;
    Point a(1.0, 1.0);
    Point b(3.0, 1.0);
    Point c(2.0, 4.0);
    Point point(2.0, 4.0);

    std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl \
    << "b(" << b.getX() << ", " << b.getY() << ")" << std::endl \
    << "c(" << c.getX() << ", " << c.getY() << ")" << std::endl \
    << "point(" << point.getX() << ", " << point.getY() << ")" << std::endl \
    << "Result: " << bsp(a, b, c, point) << std::endl;
}

int main( void )
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return (0);
}
