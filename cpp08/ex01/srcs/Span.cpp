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
	if (this->_elements.size() == this->_size)
		throw NoMoreSpaceException();
	this->_elements.push_back(n);
	++this->_size;
}

// Implement a member function to add many numbers to your Span in one call.
void Span::addNumbers(int const count, ...) {

}

// find out the shortest span or the longest span (or distance, if you prefer) between all the numbers stored, and return it. If there are no numbers stored, or only one, no span can be found. Thus, throw an exception
int Span::shortestSpan(void) {
	if (this->_elements.empty())
		throw NoElementException();
	if (this->_elements.size() == 1)
		throw OnlyOneElementException();

}

int Span::longestSpan(void) {
	if (this->_elements.empty())
		throw NoElementException();
	if (this->_elements.size() == 1)
		throw OnlyOneElementException();
	int max = this->_elements.at(0);
	int min = this->_elements.at(0);
	for (std::vector<int>::iterator it = this->_elements.begin(); it != this->_elements.end(); it++) {
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
		