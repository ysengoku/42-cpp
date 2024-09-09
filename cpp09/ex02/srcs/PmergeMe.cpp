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
		this->_vec = rhs._vec;
		this->_list = rhs._list;
		this->_size = rhs._size;
	}
	return (*this);
}

PmergeMe::PmergeMe(void) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void PmergeMe::pmergeme(void) {
	double timeV;
	// double timeL;
	try {
		timeV = sortSequence(_vec);
		// timeL = sortSequence(_list);
		std::cout << "Before:" << _input + 1 << std::endl;
		std::cout << "After: " << _vec << std::endl;
		printTime("std::vector", timeV);
		// printTime("std::list  ", timeL);
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

void PmergeMe::printTime(std::string const& numbersType, double time) {
	std::cout << std::fixed << std::setprecision(FLOATING_POINT_PRECISION);
	std::cout << "Time to process a range of " << _size << " elements with " \
	<< numbersType << " : " << time  << " us " << std::endl;	
}

/*============================================================================*/
/*       Private member functions: Merge-insert sort for vector               */
/*============================================================================*/

void PmergeMe::mergeInsertionSort(std::vector<int>& sequence) {
	int straggler = -1;
	std::vector<int> largerNumbers;
	std::vector<int> smallerNumbers;

	if (sequence.size() <= 1)
		return; 
	/* leaving one element unpaired if there is an odd number of elements. */
	if (sequence.size() % 2 != 0) {
		straggler = sequence.back();
		sequence.pop_back();
	}
	sortPairs(sequence, largerNumbers, smallerNumbers);
	mergeInsertionSort(largerNumbers);
	insertPairedSmallest(sequence, largerNumbers, smallerNumbers);
	std::vector<int>::iterator it = smallerNumbers.begin();
	std::vector<int>::iterator ite = smallerNumbers.end();
	while (it != ite) {
		binarySearchInsert(largerNumbers, *it);
		++it;
	}
	if (straggler != -1)
		binarySearchInsert(largerNumbers, straggler);
	sequence.clear();
	sequence.insert(sequence.end(), largerNumbers.begin(), largerNumbers.end());
}

/* Group the elements of X into [n/2] pairs of elements */
/* Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair. */
/* Recursively sort the [n/2] larger elements from each pair,
creating a sorted sequence S of [n/2] of the input elements, in ascending order.*/
void PmergeMe::sortPairs(std::vector<int>& sequence, std::vector<int>& larger, std::vector<int>& smaller) {
	std::vector<int>::iterator it = sequence.begin();
	std::vector<int>::iterator ite = sequence.end();
	while (it != ite && it + 1 != ite) {
		if (*it > *(it + 1)) {
			larger.push_back(*it);
			smaller.push_back(*(it + 1));
		}	
		else {
			larger.push_back(*(it + 1));
			smaller.push_back(*it);
		}
		std::advance(it, 2);
	}
}

/* Insert at the start of S the element that was paired with the first and smallest element of S */
void PmergeMe::insertPairedSmallest(std::vector<int>& sequence, std::vector<int>& larger, std::vector<int>& smaller) {
	if (larger.empty() || smaller.empty())
		return;
	int smallestInLarger = *larger.begin();
	std::vector<int>::iterator originalPosition = std::find(sequence.begin(), sequence.end(), smallestInLarger);
	int position = std::distance(sequence.begin(), originalPosition);
	int pairedNum = (position % 2 == 0) ? sequence.at(position + 1) : sequence.at(position - 1);
	larger.insert(larger.begin(), pairedNum);
	smaller.erase(std::find(smaller.begin(), smaller.end(), pairedNum));
}

void PmergeMe::binarySearchInsert(std::vector<int>& sequence, int toInsert) {
	size_t low = 0;
	size_t high = sequence.size();
	while (low < high) {
		size_t middle = low + (high - low) / 2;
		if (toInsert < sequence.at(middle))
				high = middle;
			else
				low = middle + 1;
		}
		size_t insertPosition = low;
		sequence.insert(sequence.begin() + insertPosition, toInsert);
}

/*============================================================================*/
/*       Merge-insert sort for list                                           */
/*============================================================================*/

void PmergeMe::mergeInsertionSort(std::list<int>& container) {
	(void) container;
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
