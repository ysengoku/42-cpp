/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:04 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/20 09:40:05 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

void testFromSubject(void);
void exceptionsTest(void);
void addRangeTest(void);
void manyNumbersTest(int count);

int main()
{
	testFromSubject();
	addRangeTest();
	exceptionsTest();
	manyNumbersTest(11000);
	return 0;
}

/*============================================================================*/
/*       Tests definition                                                     */
/*============================================================================*/

void testFromSubject(void) {
	std::cout << BGCYAN << " Test from subject " << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

std::vector< int > createRandomIntNumbers(int count) {
	std::vector< int > randomNumbers;
	srand(time(0));
	for (int i = 0; i < count; i++)
		randomNumbers.push_back(rand());
	return (randomNumbers);
}

void addRangeTest(void) {
	std::cout << std::endl << BGCYAN << " Add range Test " << RESET << std::endl;
	Span sp = Span(5);
	std::cout << "--- Before adding ---" << std::endl; 
	sp.printElements();
	std::cout << "--- Add an element ---" << std::endl;
	sp.addNumber(42);
	sp.printElements();
	std::cout << "--- Add range ---" << std::endl;
	std::vector< int > numbers = createRandomIntNumbers(4);
	sp.addRange< std::vector<int> >(numbers.begin(), numbers.end());
	sp.printElements();
}

void exceptionsTest(void) {
	std::cout << std::endl << BGCYAN << " Exception Test " << RESET << std::endl;
	Span sp = Span(3);
	{
		std::cout << ">>> Shortest span test with empty element..." << std::endl;
		try {
			std::cout << sp.shortestSpan() << std::endl;
		} catch (Span::TooFewElementException &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
	{
		std::cout << ">>> Longest span test with empty element..." << std::endl;
		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch (Span::TooFewElementException &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
	sp.addNumber(3);
	{
		std::cout << ">>> Shortest span test with only one element..." << std::endl;
		try {
			std::cout << sp.shortestSpan() << std::endl;
		} catch (Span::TooFewElementException &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
	{
		std::cout << ">>> Longest span test with only one element..." << std::endl;
		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch (Span::TooFewElementException &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
	sp.addNumber(3);
	sp.addNumber(3);
	{
		std::cout << ">>> Attempt to add an element beyond the size..." << std::endl;
		try {
			sp.addNumber(5);
		} catch (Span::NoMoreSpaceException &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
	{
		std::cout << ">>> Attempt to add too many elements with addRange()..." << std::endl;
		std::vector< int > numbers = createRandomIntNumbers(2);
		try {
			sp.addRange< std::vector< int > >(numbers.begin(), numbers.end());
		} catch (Span::NoMoreSpaceException &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
	{
		std::cout << ">>> Shortest span test..." << std::endl;
		try {
			std::cout << sp.shortestSpan() << std::endl;
		} catch (Span::NoSpanException &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
	{
		std::cout << ">>> Longest span test..." << std::endl;
		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch (Span::NoSpanException &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
}

void manyNumbersTest(int count) {
	std::cout << std::endl << BGCYAN << " Test with " << count <<" numbers " << RESET << std::endl;
	Span sp(count);
	std::vector< int > randomNumbers = createRandomIntNumbers(count);
	sp.addRange< std::vector< int > >(randomNumbers.begin(), randomNumbers.end() - 1);
	{
		std::cout << ">>> Shortest span test..." << std::endl;
		try {
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
	{
		std::cout << ">>> Longest span test..." << std::endl;
		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl <<std::endl;
		}
	}
}
