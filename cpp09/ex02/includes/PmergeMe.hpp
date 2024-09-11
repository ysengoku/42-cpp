/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/06 13:16:39 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <cstdlib>
# include <climits>
# include <cerrno>
# include <iomanip>
# include <algorithm>
# include <ctime>

# define FLOATING_POINT_PRECISION 5

class PmergeMe {
	public:
		PmergeMe(char** input, size_t size);
		~PmergeMe(void);
		PmergeMe(PmergeMe const& src);
		PmergeMe& operator=(PmergeMe const& rhs);

		void pmergeme(void);
		
		class InvalidValueException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class DuplicateFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	private:
		char** _input;
		size_t	_size;
		std::vector<int> _vec;
		std::list<int> _list;
		int* _insertionOrder;

		PmergeMe(void);
		
		bool isValidValue(char const*);
		int* generateInsertionOrder(size_t n);
		int* getJacobsthalNum(size_t n);
		void printTime(std::string const& containerType, double time);

		/*----- For vector -----*/
		void mergeInsertionSort(std::vector<int>&);
		void sortLargerNums(std::vector< std::pair<int, int> >& pairs);
		void insertPend(std::vector<int>& mainChain, std::vector<int>& pend);
		void binarySearchInsert(std::vector<int>& vec, int toInsert);

		/*----- For list -----*/
		void mergeInsertionSort(std::list<int>&);
		void sortLargerNums(std::list< std::pair<int, int> >& pairs);
		void insertPend(std::list<int>& mainChain, std::list<int>& pend);
		void binarySearchInsert(std::list<int>& vec, int toInsert);

		/*----- Templates -----*/
		template<class Container>
		double sortSequence(Container& container) {
			clock_t start = clock();
			for (int i = 0; _input[i]; ++i) {
				if (!isValidValue(_input[i]))
					throw InvalidValueException();
				container.push_back(atoi(_input[i]));
			}
			if (!checkDuplicate(container))
				throw DuplicateFoundException();
			_insertionOrder = generateInsertionOrder(_size / 2 + _size % 2);
			mergeInsertionSort(container);
			delete[] _insertionOrder;
			return  ((clock() - start) / (CLOCKS_PER_SEC / 1000.0));
		}

		template<class Container>
		bool checkDuplicate(Container const& container) {
			typedef typename Container::const_iterator const_iterator;
			const_iterator itBegin = container.begin();
			const_iterator itEnd = container.end();
			while (itBegin != itEnd) {
				const_iterator it = itBegin;
				while(++it != itEnd) {
					if (*itBegin == *it)
						return (false);
				}
				++itBegin;
			}
			return (true);
		}

		template<class Container, class PairContainer>
		void createSortedPairs(Container& seq, PairContainer& pairs) {
		std::vector<int>::iterator itFirst = seq.begin();
		std::vector<int>::iterator itSecond = seq.begin();
		++itSecond;
		std::vector<int>::iterator ite = seq.end();
		while (itFirst != ite && itSecond != ite) {
			if (*itFirst > *itSecond)
				pairs.push_back(std::make_pair(*itSecond, *itFirst));
			else
				pairs.push_back(std::make_pair(*itFirst, *itSecond));
			std::advance(itFirst, 2);
			std::advance(itSecond, 2);
		}
	}

	template<class PairContainer, class Container>
	void pushToMainChain(PairContainer& pairs, Container& mainChain, Container& pend) {
		typename PairContainer::iterator it = pairs.begin();
		typename PairContainer::iterator ite = pairs.end();
		if (it != ite) {
			mainChain.push_back(it->first);
			mainChain.push_back(it->second);
			++it;
		}
		while (it != ite) {
			mainChain.push_back(it->second);
			pend.push_back(it->first);
			++it;
		}
	}
};

std::ostream& operator<<(std::ostream& os, char**);

template<template <typename, typename> class Container>
std::ostream& operator<<(std::ostream& os, const Container< int, std::allocator<int> >& container) {
	typedef typename Container< int, std::allocator<int> >::const_iterator const_iterator;
	const_iterator it = container.begin();
	const_iterator ite = container.end();
	while (it != ite) {
		os << ' ' << *it;
		++it;
	}
	return (os);
}

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GREY "\e[0;90m"
# define RESET "\033[0m"

#endif
