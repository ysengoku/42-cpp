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
# include <sys/time.h>
// # include  <ctime>

# define FLOATING_POINT_PRECISION 5

// template<template <typename, typename> class Container>
// std::ostream& operator<<(std::ostream& os, const Container< int, std::allocator<int> >& container);

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

		PmergeMe(void);
		
		bool isValidValue(char const*);
		void printTime(std::string const& containerType, double time);
		void mergeInsertSort(std::vector<int>&);
		void mergeInsertSort(std::list<int>&);
		void sortPairs(std::vector<int>& vec, std::vector<int>& larger, std::vector<int>& smaller);
		void insertPairedSmallest(std::vector<int>& vec, std::vector<int>& larger, std::vector<int>& smaller);
		void binarySearchInsert(std::vector<int>& vec, int toInsert);

		template<template <typename, typename> class Container>
		double sortSequence(Container< int, std::allocator<int> >& container) {
			struct timeval begin, end;
			gettimeofday(&begin, 0);
			// clock_t start, end;
			// start = clock();

			for (int i = 1; _input[i]; ++i) {
				if (!isValidValue(_input[i]))
					throw InvalidValueException();
				container.push_back(atoi(_input[i]));
			}
			if (!checkDuplicate(container))
				throw DuplicateFoundException();
			mergeInsertSort(container);
			gettimeofday(&end, 0);
			double sec = end.tv_sec - begin.tv_sec;
			double usec = end.tv_usec - begin.tv_usec;
			return (sec * 1000000.0 + usec);
			// end = clock();
			// double sec = (end - start) / CLOCKS_PER_SEC;
			// return  (sec * 1000000.0);
		}

		template<template <typename, typename> class Container>
		bool checkDuplicate(Container< int, std::allocator<int> > const& container) {
			typedef typename Container< int, std::allocator<int> >::const_iterator const_iterator;
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
		
		// template<template <typename, typename> class Container>
		// void mergeInsertSort(Container< int, std::allocator<int> >& container) {
		// 	int straggler;
		// 	// Container< int, std::allocator<int> > tmp = container;
		// 	Container< int, std::allocator<int> > largerNumbers;
		// 	Container< int, std::allocator<int> > smallerNumbers;
		// 	Container< int, std::allocator<int> > sortedSequence;
			
		// /* Group the elements of X into [n/2] pairs of elements */
						 
		// /* leaving one element unpaired if there is an odd number of elements. */
		// 	if (_size % 2 != 0) {
		// 		straggler = container.back();
		// 		container.pop_back();
		// 	}

		// /* Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair. */
		// /* Recursively sort the [n/2] larger elements from each pair,
		// creating a sorted sequence S of [n/2] of the input elements, in ascending order.*/
		// 	typename Container< int, std::allocator<int> >::iterator it = container.begin();
		// 	typename Container< int, std::allocator<int> >::iterator ite = container.end();
		// 	while (it != ite) {
		// 		if (*it > *(it + 1)) {
		// 			largerNumbers.push_back(*it);
		// 			smallerNumbers.push_back(*(it + 1));
		// 		}	
		// 		else {
		// 			largerNumbers.push_back(*(it + 1));
		// 			smallerNumbers.push_back(*it);
		// 		}
		// 		std::advance(it, 2);
		// 	}
		// 	// mergeInsertSort(largerNumbers);
		// 	sortedSequence = largerNumbers;

		// /* Insert at the start of S the element that was paired with the first and smallest element of S */

		// /* Insert the remaining [n/2] - 1 elements of X ∖ S into S, one at a time,
		// with a binary search in subsequences of S (as described below) 
		// to determine the position at which each element should be inserted. */
			
		// 	if (_size % 2 != 0)
		// 		sortedSequence.push_back(straggler); /// ------------- temporary
		// 		// insert the straggler by using binary search
		// 	container = sortedSequence; /// ------------- temporary
		// }
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
