/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:48 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/05 09:38:33 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

PmergeMe::PmergeMe(char** input)
: _elementCount(0), _timeV(0.0), _timeL(0.0) {
	for (int i = 1; input[i]; ++i) {
		if (!isValidValue(input[i]))
			throw InvalidValueException();
		_containerV.push_back(atoi(input[i]));
		_containerL.push_back(atoi(input[i]));
		++_elementCount;
	}
	if (_elementCount < 2)
		throw TooFewElementsException();
	std::cout << GREY << "Constructor called." << RESET << std::endl;
}

PmergeMe::~PmergeMe(void) {
	std::cout << GREY << "Destructor called." << RESET << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const& src) {
	std::cout << GREY << "Copy constructor called." << RESET << std::endl;
	*this = src;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
	std::cout << GREY << "Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs) {
		this->_containerV = rhs._containerV;
		this->_containerL = rhs._containerL;
		this->_elementCount = rhs._elementCount;
		this->_timeV = rhs._timeV;
		this->_timeL = rhs._timeL;
	}
	return (*this);
}

PmergeMe::PmergeMe(void) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void PmergeMe::sort(void) {
	std::cout << "Before:  " << _containerV << std::endl;
	_timeV = mergeInsertSort(_containerV);
	_timeL = mergeInsertSort(_containerL);
	std::cout << "After:   " << _containerV << std::endl;
	printTime("std::vector", _timeV);
	printTime("std::list  ", _timeL);
}

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

bool PmergeMe::isValidValue(char* value) {
	errno = 0;
	char* p_end;
	long num = strtol(value, &p_end, 10);
	
	if (*p_end != '\0' || errno == ERANGE || num > INT_MAX || num < 0)
		return (false);
	return (true);
}

void PmergeMe::printTime(std::string const& containerType, double time) {
	std::cout << std::fixed << std::setprecision(FLOATING_POINT_PRECISION);
	std::cout << "Time to process a range of " << _elementCount << " elements with " \
	<< containerType << " : " << time  << " us " << std::endl;	
}

/*============================================================================*/
/*       Exceptions                                                           */
/*============================================================================*/

const char* PmergeMe::InvalidValueException::what() const throw() {
	return (RED "Error: Invalid value detected in the input.\n" RESET);
}

const char* PmergeMe::TooFewElementsException::what() const throw() {
	return (RED "Error: You must provide at least 2 numbers.\n" RESET);
}
