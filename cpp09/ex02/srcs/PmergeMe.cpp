/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:48 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/04 14:52:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

// template<template <typename, typename> class Container>
// PmergeMe<Container>::PmergeMe(char** input)
// : _elementCount(0), _time(0.0) {
// 	for (int i = 1; input[i]; ++i) {
// 		if (!isValidValue(input[i]))
// 			throw InvalidValueException();
// 		_container.push_back(atoi(input[i]));
// 		++_elementCount;
// 	}
// 	std::cout << GREY << "Constructor called." << RESET << std::endl;
// 	printNumbers();
// 	printTime();
// }

// template<template <typename, typename> class Container>
// PmergeMe<Container>::~PmergeMe(void) {
// 	std::cout << GREY << "Destructor called." << RESET << std::endl;
// }

template<template <typename, typename> class Container>
PmergeMe<Container>::PmergeMe(PmergeMe const& src) {
	std::cout << GREY << "Copy constructor called." << RESET << std::endl;
	*this = src;
}

template<template <typename, typename> class Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(PmergeMe const& rhs) {
	std::cout << GREY << "Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs) {
		this->_container = rhs._container;
		this->_elementCount = rhs._elementCount;
		this->_time = rhs._time;
	}
	return (*this);
}

template<template <typename, typename> class Container>
PmergeMe<Container>::PmergeMe(void) {}

// PmergeMe::PmergeMe(char** input)
// : _elementCount(0), _timeV(0.0), _timeL(0.0) {
// 	for (int i = 1; input[i]; ++i) {
// 		if (!isValidValue(input[i]))
// 			throw InvalidValueException();
// 		_containerV.push_back(atoi(input[i]));
// 		_containerL.push_back(atoi(input[i]));
// 		++_elementCount;
// 	}
// 	std::cout << GREY << "Constructor called." << RESET << std::endl;
// }

// PmergeMe::~PmergeMe(void) {
// 	std::cout << GREY << "Destructor called." << RESET << std::endl;
// }

// PmergeMe::PmergeMe(PmergeMe const& src) {
// 	std::cout << GREY << "Copy constructor called." << RESET << std::endl;
// 	*this = src;
// }

// PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
// 	std::cout << GREY << "Copy assignment operator called." << RESET << std::endl;
// 	if (this != &rhs) {
// 		this->_containerV = rhs._containerV;
// 		this->_containerL = rhs._containerL;
// 	}
// 	return (*this);
// }

// PmergeMe::PmergeMe(void) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

// template<template <typename, typename> class Container>
// void PmergeMe<Container>::sort(void) {
	
// }

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

// template<template <typename, typename> class Container>
// bool PmergeMe<Container>::isValidValue(char* value) {
// 	errno = 0;
// 	char* p_end;
// 	long num = strtol(value, &p_end, 10);
	
// 	if (*p_end != '\0' || errno == ERANGE || num > INT_MAX || num < INT_MIN)
// 		return (false);
// 	return (true);
// }

// template<template <typename, typename> class Container>
// void PmergeMe<Container>::printNumbers(void) {
// 	typename Container<int, std::allocator<int> >::iterator it = _container.begin();
// 	typename Container<int, std::allocator<int> >::iterator ite = _container.end();
// 	while (it != ite - 1) {
// 		std::cout << *it << ' ';
// 		++it;
// 	}
// 	std::cout << *it << std::endl;
// }

// template<template <typename, typename> class Container>
// void PmergeMe<Container>::printTime(void) {
// 	std::cout << std::fixed << std::setprecision(FLOATING_POINT_PRECISION);
// 	std::cout << "Time to process a range of " \
// 	<< _elementCount << " elements with std::vector : " \
// 	<< _time  << " us " << std::endl;	
// }

/*============================================================================*/
/*       Exceptions                                                           */
/*============================================================================*/

// template<template <typename, typename> class Container>
// const char* PmergeMe<Container>::InvalidValueException::what() const throw() {
// 	return (RED "Error: Invalid value detected in the input.\n" RESET);
// }
