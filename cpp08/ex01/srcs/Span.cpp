/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/13 14:27:07 by yusengok         ###   ########.fr       */
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

Span::Span(Span const& src) : Span(src) {
	std::cout << GREY << "Span: Copy constructor called" << RESET << std::endl;
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
	++_size;
}

// Implement a member function to add many numbers to your Span in one call.
void Span::addNumbers(int const count, ...) {

}

int Span::shortestSpan(void) {
	if (_elements.empty())
		throw NoElementException();
	if (_elements.size() == 1)
		throw OnlyOneElementException();
	std::sort(_elements.begin(), _elements.end());
	int shortestSpan = _elements.at(1) - _elements.at(0);
	for (std::vector<int>::iterator it = _elements.begin(); it != _elements.end(); it++) {
		if (shortestSpan > *(it + 1) - *it)
			shortestSpan = *(it + 1) - *it;
	}
	if (shortestSpan == 0)
		throw NoSpanException();
	return (shortestSpan);
}

int Span::longestSpan(void) {
	if (_elements.empty())
		throw NoElementException();
	if (_elements.size() == 1)
		throw OnlyOneElementException();
	int max = _elements.at(0);
	int min = _elements.at(0);
	for (std::vector<int>::iterator it = _elements.begin(); it != _elements.end(); it++) {
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
	}
	if (min == max)
		throw NoSpanException();
	return (max - min);
}

/*============================================================================*/
/*       Exception                                                            */
/*============================================================================*/

const char* Span::NoMoreSpaceException::what() const throw() {
	return (RED "There is no space left to add a new element." RESET);
}

const char* Span::NoElementException::what() const throw() {
	return (RED "The container is empty." RESET);
}

const char* Span::OnlyOneElementException::what() const throw() {
	return (RED "There is only one element in the container." RESET);
}

const char* Span::NoSpanException::what() const throw() {
	return (RED "No span can be found" RESET);
}
		