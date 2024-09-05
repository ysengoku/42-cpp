/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:48 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/05 14:33:21 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

PmergeMe::PmergeMe(char** input)
: _input(input), _size(0), _timeV(0.0), _timeD(0.0) {
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
		this->_containerD = rhs._containerD;
		this->_size = rhs._size;
		this->_timeV = rhs._timeV;
		this->_timeD = rhs._timeD;
	}
	return (*this);
}

PmergeMe::PmergeMe(void) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void PmergeMe::sort(void) {
	try {
		_timeV = mergeInsertSort(_containerV);
		_timeD = mergeInsertSort(_containerD);

		std::cout << "Before:  ";
		int i;
		for (i = 1; _input[i + 1]; ++i)
			std::cout << _input[i] << ' ';
		std::cout << _input[i] << std::endl;
		std::cout << "After:   " << _containerV << std::endl;
		printTime("std::vector", _timeV);
		printTime("std::deque ", _timeD);
	}
	catch (std::exception &e) {
		std::cerr << e.what();
	}
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
	std::cout << "Time to process a range of " << _size << " elements with " \
	<< containerType << " : " << time  << " us " << std::endl;	
}

/*============================================================================*/
/*       Exceptions                                                           */
/*============================================================================*/

const char* PmergeMe::InvalidValueException::what() const throw() {
	return (RED "Error: Invalid value detected in the input.\n" RESET);
}

