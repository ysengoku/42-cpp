/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/20 09:42:39 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Span::Span(void) {}

Span::Span(unsigned int n) : _size(n) {
	std::cout << GREY << "Span: Constructor called" << RESET << std::endl;
}

Span::Span(Span const& src) {
	std::cout << GREY << "Span: Copy constructor called" << RESET << std::endl;
	*this = src;
}

Span& Span::operator=(Span const& rhs) {
	if (this != &rhs) {
		this->_size = rhs._size;
		this->_elements.assign(rhs._elements.begin(), rhs._elements.end());
	}
	return (*this);
}

Span::~Span(void) {
	std::cout << GREY << "Span: Destructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void Span::addNumber(int n) {
	if (_elements.size() == _size)
		throw NoMoreSpaceException();
	_elements.push_back(n);
}

unsigned int Span::shortestSpan(void) const {
	if (_elements.size() <= 1)
		throw TooFewElementException();
	std::vector< int > tmp = _elements;
	std::sort(tmp.begin(), tmp.end());
	int span = tmp.at(1) - tmp.at(0);
	for (std::vector< int >::iterator it = tmp.begin(); it != tmp.end() - 1; it++) {
		if (span > *(it + 1) - *it && (*(it + 1) - *it != 0))
			span = *(it + 1) - *it;
	}
	if (span == 0)
		throw NoSpanException();
	return (span);
}

unsigned int Span::longestSpan(void) const {
	if (_elements.size() <= 1)
		throw TooFewElementException();
	int min = *(std::min_element(_elements.begin(), _elements.end()));
	int max = *(std::max_element(_elements.begin(), _elements.end()));
	if (min == max)
		throw NoSpanException();
	return (max - min);
}

void Span::printElements(void) const {
	if (_elements.empty())
		std::cout << RED << "No element found" << RESET << std::endl;
	for (std::vector< int >::const_iterator it = _elements.begin(); it != _elements.end(); it++)
		std::cout << *it << std::endl;
}

/*============================================================================*/
/*       Exception                                                            */
/*============================================================================*/

const char* Span::NoMoreSpaceException::what() const throw() {
	return (RED "There is no space left to add a new element." RESET);
}

const char* Span::TooFewElementException::what() const throw() {
	return (RED "Not enough elements found." RESET);
}

const char* Span::NoSpanException::what() const throw() {
	return (RED "No span can be found" RESET);
}
		