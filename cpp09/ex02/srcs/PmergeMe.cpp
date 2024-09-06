/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:48 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/06 14:41:06 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

PmergeMe::PmergeMe(char** input, size_t size)
: _input(input), _size(size) {
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
		this->_size = rhs._size;
		// this->_timeV = rhs._timeV;
		// this->_timeL = rhs._timeL;
	}
	return (*this);
}

PmergeMe::PmergeMe(void) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void PmergeMe::pmergeme(void) {
	double _timeV;
	double _timeL;
	try {
		_timeV = sortSequence(_containerV);
		_timeL = sortSequence(_containerL);
		std::cout << "Before:" << _input + 1 << std::endl;
		std::cout << "After: " << _containerV << std::endl;
		printTime("std::vector", _timeV);
		printTime("std::list  ", _timeL);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

bool PmergeMe::isValidValue(char const* value) {
	errno = 0;
	char* p_end;
	long num = strtol(value, &p_end, 10);
	
	if (*p_end != '\0' || errno == ERANGE || num > INT_MAX || num < 0)
		return (false);
	return (true);
}

void PmergeMe::mergeInsertSort(std::vector<int>& vec) {
	int straggler = -1;
	std::vector<int> largerNumbers;
	std::vector<int> smallerNumbers;

	if (vec.size() == 1)
		return; 
	/* leaving one element unpaired if there is an odd number of elements. */
	if (_size % 2 != 0) {
		straggler = vec.back();
		vec.pop_back();
	}

	/* Group the elements of X into [n/2] pairs of elements */
	/* Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair. */
	/* Recursively sort the [n/2] larger elements from each pair,
	creating a sorted sequence S of [n/2] of the input elements, in ascending order.*/
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	while (it != ite && it + 1 != ite) {
		if (*it > *(it + 1)) {
			largerNumbers.push_back(*it);
			smallerNumbers.push_back(*(it + 1));
		}	
		else {
			largerNumbers.push_back(*(it + 1));
			smallerNumbers.push_back(*it);
		}
		std::advance(it, 2);
	}
	
	mergeInsertSort(largerNumbers);

	/* Insert at the start of S the element that was paired with the first and smallest element of S */
	int smallestInLarger = *(std::min_element(largerNumbers.begin(), largerNumbers.end()));
	std::vector<int>::iterator smallestInLargerPos = std::find(vec.begin(), vec.end(), smallestInLarger);
	int position = std::distance(vec.begin(), smallestInLargerPos);
	int paired = (position % 2 == 0) ? vec.at(position + 1) : vec.at(position - 1);
	largerNumbers.insert(largerNumbers.begin(), paired);
	smallerNumbers.erase(std::find(smallerNumbers.begin(), smallerNumbers.end(), paired));

	/* Insert the remaining [n/2] - 1 elements of X ∖ S into S, one at a time,
	with a binary search in subsequences of S (as described below) 
	to determine the position at which each element should be inserted. */
	/// ------------- temporary ----------------------
	largerNumbers.insert(largerNumbers.begin(), smallerNumbers.begin(), smallerNumbers.end());
		
	if (straggler != -1) {
		/// ------------- temporary ------------------
		std::vector<int>::iterator stragglerPos = std::lower_bound(largerNumbers.begin(), largerNumbers.end(), straggler);
		largerNumbers.insert(stragglerPos, straggler);
	// insert the straggler by using binary search
	}
	vec.clear();
	vec.insert(vec.end(), largerNumbers.begin(), largerNumbers.end());
}

void PmergeMe::mergeInsertSort(std::list<int>& container) {
	(void) container;
}

void PmergeMe::printTime(std::string const& numbersType, double time) {
	std::cout << std::fixed << std::setprecision(FLOATING_POINT_PRECISION);
	std::cout << "Time to process a range of " << _size << " elements with " \
	<< numbersType << " : " << time  << " us " << std::endl;	
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

std::ostream& operator<<(std::ostream& os, char** argv) {
	for (int i = 0; argv[i]; ++i)
		std::cout << ' ' << argv[i];
	return (os);
}

/*============================================================================*/
/*       Exceptions                                                           */
/*============================================================================*/

const char* PmergeMe::InvalidValueException::what() const throw() {
	return (RED "Error: Invalid value detected in the input." RESET);
}

const char* PmergeMe::DuplicateFoundException::what() const throw() {
	return (RED "Error: Duplicate number found." RESET);	
}
