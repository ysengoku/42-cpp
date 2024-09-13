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
: _input(input), _size(size), _time(0) {
	#ifdef DEBUG
		std::cout << GREY << "Constructor called." << RESET << std::endl;
	#endif
	std::cout << "Before:" << _input << std::endl;
}

PmergeMe::~PmergeMe(void) {
	#ifdef DEBUG
		std::cout << GREY << "Destructor called." << RESET << std::endl;
	#endif
}

PmergeMe::PmergeMe(PmergeMe const& src) {
	*this = src;
	#ifdef DEBUG
		std::cout << GREY << "Copy constructor called." << RESET << std::endl;
	#endif
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
	if (this != &rhs) {
		this->_vec = rhs._vec;
		this->_list = rhs._list;
		this->_size = rhs._size;
	}
	#ifdef DEBUG
		std::cout << GREY << "Copy assignment operator called." << RESET << std::endl;
	#endif
	return (*this);
}

PmergeMe::PmergeMe(void) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

std::vector<int>& PmergeMe::getVector(void) {
	return (_vec);
}

std::list<int>& PmergeMe::getList(void) {
	return (_list);
}

void PmergeMe::printTime(std::string const& numbersType) {
	std::cout << std::fixed << std::setprecision(FLOATING_POINT_PRECISION);
	std::cout << "Time to process a range of " << _size << " elements with " \
	<< numbersType << " : " << _time  << " ms " << std::endl;	
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

int PmergeMe::jacobsthalNumber(size_t n) {
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2));
}

/*============================================================================*/
/*       Private member functions: Merge-insert sort for vector               */
/*============================================================================*/

void PmergeMe::mergeInsertionSort(std::vector<int>& sequence) {
	int straggler = -1;
	std::vector< std::pair<int, int> > pairs;
	std::vector<int> mainChain;
	std::vector<int> pend;

	if (sequence.size() <= 1)
		return;
	if (sequence.size() % 2 != 0) {
		straggler = sequence.back();
		sequence.pop_back();
	}
	createSortedPairs(sequence, pairs);
	pushToMainChain(pairs, mainChain, pend);
	mergeInsertionSort(mainChain);

	// sortLargerNums(pairs);
	// mainChain.push_back(pairs.front().first);

	
	if (straggler != -1)
		pend.push_back(straggler);
	insertPend(mainChain, pend);
	sequence.clear();
	sequence.insert(sequence.end(), mainChain.begin(), mainChain.end());
}

void PmergeMe::insertPend(std::vector<int>& mainChain, std::vector<int>& pend) {
	int	pendSize = pend.size();
	size_t i = 2;
	int currentJacobsthal = jacobsthalNumber(i);

	if (pendSize == 0)
		return ;
	while (currentJacobsthal < pendSize) {
		binarySearchInsert(mainChain, pend.at(currentJacobsthal), 0, mainChain.size());

		pend.at(currentJacobsthal) = -1;
		currentJacobsthal = jacobsthalNumber(++i);
	}
	for (int j = 0; j < pendSize; ++j) {
		if (pend.at(j) != -1)
			binarySearchInsert(mainChain, pend.at(j), 0, mainChain.size());
	}
}

void PmergeMe::binarySearchInsert(std::vector<int>& mainChain, int toInsert, size_t start, size_t end) {
	size_t low = start;
	size_t high = end;

	// size_t count = 0;
	while (low < high) {
		size_t middle = low + (high - low) / 2;
		if (toInsert < mainChain.at(middle))
			high = middle;
		else
			low = middle + 1;
		// ++count;
	}
	std::vector<int>::iterator insertPosition = mainChain.begin() + low;
	mainChain.insert(insertPosition, toInsert);
	// if (count > 4)
	// 	std::cout << RED << count << RESET << std::endl;
	// else
	// 	std::cout << GREEN << count << RESET << std::endl;
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
