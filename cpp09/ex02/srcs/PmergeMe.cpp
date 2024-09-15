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
		this->_input = rhs._input;
		this->_size = rhs._size;
		this->_time = rhs._time;
		this->_vec = rhs._vec;
		this->_list = rhs._list;
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
/*       Functions overloading for vector                                     */
/*============================================================================*/

void PmergeMe::sortByPair(std::vector<int>& seq, size_t blockSize, size_t blockCount) {
	std::vector<int>::iterator itLeft = seq.begin();
	std::advance(itLeft, blockSize - 1);
	std::vector<int>::iterator itRight = seq.begin();
	std::advance(itRight, blockSize * 2 - 1);

	if (blockCount < 2)
		return;
	#ifdef DEBUG
		std::cout << GREEN "\n===== < Sort by Pair > Block size: " << blockSize << "  Block count: " << blockCount << " =====" RESET << std::endl;
	#endif
	for (size_t i = 0; i < blockCount / 2; ++i) {
		#ifdef DEBUG
			std::cout << "Comapring [" << *itLeft << " - " << *itRight << "]" << std::endl;
		#endif
		if (*itLeft > *itRight) {
			size_t leftIndex = std::distance(seq.begin(), itLeft);
			size_t rightIndex = std::distance(seq.begin(), itRight);
			for (size_t i = 0; i < blockSize; ++i)
				std::swap(seq.at(leftIndex - i), seq.at(rightIndex - i));
			#ifdef DEBUG
				std::cout << CYAN << "Swapped ---> [" << *itLeft << " - " << *itRight << ']' << RESET << std::endl;
			#endif
		}
		std::advance(itLeft, blockSize * 2);
		std::advance(itRight, blockSize * 2);
	}
	#ifdef DEBUG
		std::cout << "Sequence after sort by pair:" << seq << std::endl;
	#endif
}

void PmergeMe::splitAndBinaryInsert(std::vector<int>& seq, size_t blockSize, size_t blockCount) {
	v_iter_pair_container mainChain;
	v_iter_pair_container pend;
	int pendSize;

	if (blockCount < 2)
		return;
	bool hasLeftover = blockCount % 2;
	pushToMainChain(seq, mainChain, pend, blockSize, blockCount);
	pendSize= pend.size();
	if (hasLeftover) 
		pendSize -= 1;
	insertPendElements(mainChain, pend, pendSize, blockSize);
	if (hasLeftover) {
		#ifdef DEBUG
			std::cout << "Inserting (leftover) " << pend.at(pendSize).first << std::endl;
		#endif
		v_iter_pair_container::iterator start = mainChain.begin();
		v_iter_pair_container::iterator end = mainChain.end();
		binarySearchInsert(mainChain, pend.at(pendSize), start, end);
	}
	#ifdef DEBUG
		std::cout << "\nMain chain (after insertion): ";
		for (v_iter_pair_container::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
			std::cout << it->first << ' ';
		std::cout << std::endl << std::endl;
	#endif
	rebuildSequence(seq, mainChain, blockSize, blockCount);
}

void PmergeMe::insertPendElements(v_iter_pair_container& mainChain, v_iter_pair_container& pend, int pendSize, size_t blockSize) {
	size_t i = 2;
	int target = jacobsthalNumber(i);
	v_iter_pair_container::iterator start = mainChain.begin();
	v_iter_pair_container::iterator end = mainChain.end();
	v_iter_pair_container::iterator lastInserted = mainChain.begin();

	while (target < pendSize) {
		#ifdef DEBUG
			std::cout << "Inserting " << pend.at(target).first << std::endl;
		#endif
		findBinarySearchRange(mainChain, pend, start, end, lastInserted, target, blockSize);
		lastInserted = binarySearchInsert(mainChain, pend.at(target), start, end);
		pend.at(target).first = -1;
		target = jacobsthalNumber(++i);
	}
	for (target = 0; target < pendSize; ++target) {
		if (pend.at(target).first != -1) {
			#ifdef DEBUG
				std::cout << "Inserting " << pend.at(target).first << std::endl;
			#endif
			findBinarySearchRange(mainChain, pend, start, end, lastInserted, target, blockSize);
			lastInserted = binarySearchInsert(mainChain, pend.at(target), start, end);
		}
	}
}

void PmergeMe::findBinarySearchRange
(v_iter_pair_container& mainChain, v_iter_pair_container& pend,
 v_iter_pair_container::iterator& start, v_iter_pair_container::iterator& end,
 v_iter_pair_container::iterator& lastInserted, int target, size_t blockSize) {
	if (lastInserted != mainChain.end() && pend.at(target).first > lastInserted->first) {
		start = lastInserted + 1;
		std::vector<int>::const_iterator itInSequence = pend.at(target).second;
		std::vector<int>::const_iterator itPairElement = itInSequence + blockSize;
		end = std::find(mainChain.begin(), mainChain.end(), std::make_pair(*itPairElement, itPairElement));
	}
	else {
		start = mainChain.begin();
		end = lastInserted;
	}
	#ifdef DEBUG
		std::cout << "Binary Search Start: " << start->first << std::endl;
		std::cout << "Binary Search End:   " << end->first << RESET << std::endl;
	#endif
}

void PmergeMe::rebuildSequence(std::vector<int>& seq, v_iter_pair_container& mainChain, size_t blockSize, size_t blockCount) {
	std::vector<int> tmp;
	std::vector<int>::const_iterator itSequence;
	for (size_t i = 0; i < blockCount; ++i) {
		itSequence = (mainChain.begin() + i)->second;
		#ifdef DEBUG
			std::cout << "Target end:   " << *itSequence << std::endl;
		#endif
		itSequence -= blockSize - 1;
		#ifdef DEBUG
			std::cout << "Target start: " << *itSequence << std::endl << std::endl;
		#endif
		for (size_t j = 0; j < blockSize; ++j) {
			tmp.push_back(*itSequence);
			++itSequence;
		}
	}
	size_t remainingCount = seq.size() - tmp.size();
	std::vector<int>::iterator it = seq.end() - remainingCount;
	for (size_t i = 0; i < remainingCount; ++i) {
		tmp.push_back(*it);
		++it;
	}
	#ifdef DEBUG
		std::cout << "\nSequence BEFORE:" << seq << std::endl;
	#endif
	seq.clear();
	seq.insert(seq.end(), tmp.begin(), tmp.end());
	#ifdef DEBUG
		std::cout << "Rebuilt sequence:" << seq << std::endl;
		if (seq.size() != _size)
			std::cout << RED << "Error: Rebuilt sequence size is not equal to the original size." << RESET << std::endl << std::endl;
	#endif
}

/*============================================================================*/
/*       Functions overloading for list                                       */
/*============================================================================*/

void PmergeMe::sortByPair(std::list<int>& seq, size_t blockSize, size_t blockCount) {
	std::list<int>::iterator itLeft = seq.begin();
	std::advance(itLeft, blockSize - 1);
	std::list<int>::iterator itRight = seq.begin();
	std::advance(itRight, blockSize * 2 - 1);

	if (blockCount < 2)
		return;
	#ifdef DEBUG
		std::cout << GREEN "\n===== < Sort by Pair > Block size: " << blockSize << "  Block count: " << blockCount << " =====" RESET << std::endl;
	#endif
	for (size_t i = 0; i < blockCount / 2; ++i) {
		#ifdef DEBUG
			std::cout << "Comapring [" << *itLeft << " - " << *itRight << "]" << std::endl;
		#endif
		if (*itLeft > *itRight) {
			std::list<int>::iterator itLeftBlockStart = itLeft;
			std::list<int>::iterator itRightBlockStart = itRight;
			for (size_t j = 0; j < blockSize; ++j) {
				std::iter_swap(itLeftBlockStart, itRightBlockStart);
				--itLeftBlockStart;
				--itRightBlockStart;
			}
			#ifdef DEBUG
				std::cout << CYAN << "Swapped ---> [" << *itLeft << " - " << *itRight << ']' << RESET << std::endl;
			#endif
		}
		std::advance(itLeft, blockSize * 2);
		std::advance(itRight, blockSize * 2);
	}
	#ifdef DEBUG
		std::cout << "Sequence after sort by pair:" << seq << std::endl;
	#endif
}

void PmergeMe::splitAndBinaryInsert(std::list<int>& seq, size_t blockSize, size_t blockCount) {
	l_iter_pair_container mainChain;
	l_iter_pair_container pend;
	int pendSize;

	if (blockCount < 2)
		return;
	bool hasLeftover = blockCount % 2;
	pushToMainChain(seq, mainChain, pend, blockSize, blockCount);
	pendSize= pend.size();
	if (hasLeftover) 
		pendSize -= 1;
	insertPendElements(mainChain, pend, pendSize, blockSize);
	if (hasLeftover) {
		l_iter_pair_container::iterator start = mainChain.begin();
		l_iter_pair_container::iterator end = mainChain.end();
		l_iter_pair_container::iterator toInsert = pend.end();
		#ifdef DEBUG
			std::cout << "Inserting (leftover) " << toInsert->first << std::endl;
		#endif
		--toInsert;
		binarySearchInsert(mainChain, *toInsert, start, end);
	}
	#ifdef DEBUG
		std::cout << "\nMain chain (after insertion): ";
		for (l_iter_pair_container::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
			std::cout << it->first << ' ';
		std::cout << std::endl << std::endl;
	#endif
	rebuildSequence(seq, mainChain, blockSize, blockCount);
}

void PmergeMe::insertPendElements(l_iter_pair_container& mainChain, l_iter_pair_container& pend, int pendSize, size_t blockSize) {
	size_t i = 2;
	int target = jacobsthalNumber(i);
	l_iter_pair_container::iterator start = mainChain.begin();
	l_iter_pair_container::iterator end = mainChain.end();
	l_iter_pair_container::iterator lastInserted = mainChain.begin();

	while (target < pendSize) {
		findBinarySearchRange(mainChain, pend, start, end, lastInserted, target, blockSize);
		l_iter_pair_container::iterator toInsert = pend.begin();
		std::advance(toInsert, target);
		#ifdef DEBUG
			std::cout << "Inserting " << toInsert->first << std::endl;
		#endif
		lastInserted = binarySearchInsert(mainChain, *toInsert, start, end);
		toInsert->first = -1;
		target = jacobsthalNumber(++i);
	}
	for (target = 0; target < pendSize; ++target) {
		l_iter_pair_container::iterator toInsert = pend.begin();
		std::advance(toInsert, target);
		if (toInsert->first != -1) {
			#ifdef DEBUG
				std::cout << "Inserting " << toInsert->first << std::endl;
			#endif
			findBinarySearchRange(mainChain, pend, start, end, lastInserted, target, blockSize);
			lastInserted = binarySearchInsert(mainChain, *toInsert, start, end);
		}
	}
}

void PmergeMe::findBinarySearchRange
(l_iter_pair_container& mainChain, l_iter_pair_container& pend,
 l_iter_pair_container::iterator& start, l_iter_pair_container::iterator& end,
 l_iter_pair_container::iterator& lastInserted, int target, size_t blockSize) {
	l_iter_pair_container::iterator toInsert = pend.begin();
	std::advance(toInsert, target);
	if (lastInserted != mainChain.end() && toInsert->first > lastInserted->first) {
		start = lastInserted;
		++start;
		std::list<int>::const_iterator itInSequence = toInsert->second;
		std::list<int>::const_iterator itPairElement = itInSequence;
		std::advance(itPairElement, blockSize);
		end = std::find(mainChain.begin(), mainChain.end(), std::make_pair(*itPairElement, itPairElement));
	}
	else {
		start = mainChain.begin();
		end = lastInserted;
	}
	#ifdef DEBUG
		std::cout << "Binary Search Start: " << start->first << std::endl;
		std::cout << "Binary Search End:   " << end->first << RESET << std::endl;
	#endif
}

void PmergeMe::rebuildSequence(std::list<int>& seq, l_iter_pair_container& mainChain, size_t blockSize, size_t blockCount) {
	std::list<int> tmp;
	std::list<int>::const_iterator itSequence;
	for (size_t i = 0; i < blockCount; ++i) {
		l_iter_pair_container::iterator itMainChain = mainChain.begin();
		std::advance(itMainChain, i);
		itSequence = itMainChain->second;
		#ifdef DEBUG
			std::cout << "Target end:   " << *itSequence << std::endl;
		#endif
		std::advance(itSequence, -(blockSize - 1));
		#ifdef DEBUG
			std::cout << "Target start: " << *itSequence << std::endl << std::endl;
		#endif
		for (size_t j = 0; j < blockSize; ++j) {
			tmp.push_back(*itSequence);
			++itSequence;
		}
	}
	size_t remainingCount = seq.size() - tmp.size();
	std::list<int>::iterator it = seq.end();
	std::advance(it, -remainingCount);
	for (size_t i = 0; i < remainingCount; ++i) {
		tmp.push_back(*it);
		++it;
	}
	#ifdef DEBUG
		std::cout << "\nSequence BEFORE:" << seq << std::endl;
	#endif
	seq.clear();
	seq.insert(seq.end(), tmp.begin(), tmp.end());
	#ifdef DEBUG
		std::cout << "Rebuilt sequence:" << seq << std::endl;
		if (seq.size() != _size)
			std::cout << RED << "Error: Rebuilt sequence size is not equal to the original size." << RESET << std::endl << std::endl;
	#endif
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
