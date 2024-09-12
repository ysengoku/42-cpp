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
	double timeL;
		timeV = sortSequence(_vec);
		timeL = sortSequence(_list);
		std::cout << "Before:" << _input << std::endl;
		std::cout << "After: " << _vec << std::endl;
		printTime("std::vector", timeV);
		printTime("std::list  ", timeL);

		///// DEBUG ///////////////////////////////////////////////////////////
		std::cout << "\n===== Check if sorted =====\n";
		std::cout << "VECTOR: ";
		std::is_sorted(_vec.begin(), _vec.end()) ? std::cout << GREEN << "SUCCESS!" << RESET : std::cout << RED << "FAILED" << RESET;
		std::cout << std::endl;
		std::cout << "LIST: ";
		std::is_sorted(_list.begin(), _list.end()) ? std::cout << GREEN << "SUCCESS!" << RESET : std::cout << RED << "FAILED" << RESET;
		std::cout << std::endl;
		///////////////////////////////////////////////////////////////////////
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

void PmergeMe::printTime(std::string const& numbersType, double time) {
	std::cout << std::fixed << std::setprecision(FLOATING_POINT_PRECISION);
	std::cout << "Time to process a range of " << _size << " elements with " \
	<< numbersType << " : " << time  << " ms " << std::endl;	
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
	mergeInsertionSort(pend);

	////////// NEED TO BE FIXED //////////
	// std::vector< std::pair<int, int> >::iterator it = pairs.begin();
	// std::vector< std::pair<int, int> >::iterator ite = pairs.end();
	// while (it != ite) {
	// 	if  (it->second == mainChain.front()) {
	// 		mainChain.insert(mainChain.begin(), it->first);
	// 		break;
	// 	}
	// 	++it;
	// }
	// std::vector<int>::iterator itPend = std::find(pend.begin(), pend.end(), mainChain.front());
	// if (itPend != pend.end())
	// 	pend.erase(itPend);
	
	if (straggler != -1)
		pend.push_back(straggler);
	insertPend(mainChain, pend);
	sequence.clear();
	sequence.insert(sequence.end(), mainChain.begin(), mainChain.end());
}

void PmergeMe::sortLargerNums(std::vector< std::pair<int, int> >& pairs) {
	std::vector<int> tmp;
	std::vector< std::pair<int, int> >::iterator it = pairs.begin();
	std::vector< std::pair<int, int> >::iterator ite = pairs.end();

	while (it != ite) {
		tmp.push_back(it->second);
		++it;
	}
	mergeInsertionSort(tmp);

	//////// DOESN'T WORK WELL //////////
	it = pairs.begin();
	while (it != ite) {
		std::vector<int>::iterator itTmp = tmp.begin();
		it->second = *itTmp;
		tmp.erase(itTmp);
		++it;
	}
	/////////////////////////////////////
}

// void PmergeMe::insertPend(std::vector<int>& mainChain, std::vector<int>& pend) {
// 	size_t	pendSize = pend.size();
// 	size_t i = 3;
// 	size_t count = 2;
// 	int currentJacobsthal;
// 	int previousJacobsthal = jacobsthalNumber(i - 1);
// 	int jacobsthalDiff;
	
// 	if (pendSize == 0)
// 		return ;
// 	if (pendSize == 1) {
// 		binarySearchInsert(mainChain, pend.at(0));
// 		return ;
// 	}
// 	binarySearchInsert(mainChain, pend.at(1));
// 	binarySearchInsert(mainChain, pend.at(0));
// 	while (count < pendSize) {
// 		currentJacobsthal = jacobsthalNumber(i);
// 		jacobsthalDiff = currentJacobsthal - previousJacobsthal;
// 		while (jacobsthalDiff > 0) {
// 			if (currentJacobsthal < static_cast<int>(pendSize)){
// 				binarySearchInsert(mainChain, pend.at(currentJacobsthal));
// 				++count;
// 			}
// 			--currentJacobsthal;
// 			--jacobsthalDiff;
// 		}
// 		++i;
// 		previousJacobsthal = currentJacobsthal;
// 	}
// }

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

// void PmergeMe::binarySearchInsert(std::vector<int>& mainChain, int toInsert) {
// 	size_t low = 0;
// 	size_t high = mainChain.size();

// 	while (low < high) {
// 		size_t middle = low + (high - low) / 2;
// 		if (toInsert < mainChain.at(middle))
// 			high = middle;
// 		else
// 			low = middle + 1;
// 	}
// 	size_t insertPosition = low;
// 	mainChain.insert(mainChain.begin() + insertPosition, toInsert);
// }

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
