/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/05 14:33:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
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

		void sort(void);
		
		class InvalidValueException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	private:
		char** _input;
		size_t	_size;
		std::vector<int> _containerV;
		std::deque<int> _containerD;
		double _timeV;
		double _timeD;

		PmergeMe(void);
		
		bool isValidValue(char*);
		void printTime(std::string const& containerType, double time);

		template<template <typename, typename> class Container>
		double mergeInsertSort(Container< int, std::allocator<int> >& container) {
			int straggler;
			struct timeval begin, end;
			gettimeofday(&begin, 0);
			// clock_t start, end;
			// start = clock();
			Container< int, std::allocator<int> > tmp;
			Container< int, std::allocator<int> > sortedSequence;
			for (int i = 1; _input[i]; ++i) {
				if (!isValidValue(_input[i]))
					throw InvalidValueException();
				tmp.push_back(atoi(_input[i]));
			}
			// ----- Check duplicated elements
			if (_size % 2 != 0) {
				straggler = tmp.back();
				tmp.pop_back();
			}

// Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
// Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.

// Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order.
// Insert at the start of S the element that was paired with the first and smallest element of S.
// Insert the remaining [n/2] - 1 elements of X ∖ S into S, one at a time, with a specially chosen insertion ordering described below. Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.

			/* Sort each pair */
			typename Container< int, std::allocator<int> >::iterator it = tmp.begin();
			typename Container< int, std::allocator<int> >::iterator ite = tmp.end();
			while (it != ite) {
				if (*it > *(it + 1))
					std::swap(*it, *(it + 1));
				std::advance(it, 2);
			}
			// std::cout << tmp << std::endl;
			
			// Sort according to grater value of pair (recursive)
			// Push the first pair to container
			// Push larger ones of each pair to container
			// Insert the remaining of tmp by using binary search

			if (_size % 2 != 0)
				tmp.push_back(straggler); /// ------------- temporary
				// insert the straggler by using binary search
			container = tmp; /// ------------- temporary

			gettimeofday(&end, 0);
			long sec = end.tv_sec - begin.tv_sec;
			long usec = end.tv_usec - begin.tv_usec;
			return (sec * 1000000 + usec);
			// end = clock();
			// double sec = (end - start) / CLOCKS_PER_SEC;
			// return  (sec * 1000000.0);
		}		
};

template<template <typename, typename> class Container>
std::ostream& operator<<(std::ostream& os, const Container< int, std::allocator<int> >& container) {
	typename Container< int, std::allocator<int> >::const_iterator it = container.begin();
	typename Container< int, std::allocator<int> >::const_iterator ite = container.end();
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

// template<template <typename, typename> class Container>
// class PmergeMe {
// 	private:
// 		Container<int, std::allocator<int> > _container;
// 		int	_elementCount;
// 		double _time;
		
// 		PmergeMe(void);

// 		bool isValidValue(char* value)  {
// 			errno = 0;
// 			char* p_end;
// 			long num = strtol(value, &p_end, 10);
			
// 			if (*p_end != '\0' || errno == ERANGE || num > INT_MAX || num < INT_MIN)
// 				return (false);
// 			return (true);
// 		}

// 	public:
// 		PmergeMe(char** input) : _elementCount(0), _time(0.0) {
// 			for (int i = 1; input[i]; ++i) {
// 				if (!isValidValue(input[i]))
// 					throw InvalidValueException();
// 				_container.push_back(atoi(input[i]));
// 				++_elementCount;
// 			}
// 			std::cout << GREY << "Constructor called." << RESET << std::endl;
// 		}
		
// 		~PmergeMe(void) {
// 			std::cout << GREY << "Destructor called." << RESET << std::endl;
// 		}
		
// 		PmergeMe(PmergeMe const& src);
// 		PmergeMe& operator=(PmergeMe const& rhs);

// 		void sort(void) {
// 			printTime();
// 		}

// 		void printNumbers(void)  {
// 			typename Container<int, std::allocator<int> >::iterator it = _container.begin();
// 			typename Container<int, std::allocator<int> >::iterator ite = _container.end();
// 			while (it != ite - 1) {
// 				std::cout << *it << ' ';
// 				++it;
// 			}
// 			std::cout << *it << std::endl;
// 		}

// 		void printTime(void) {
// 			std::cout << std::fixed << std::setprecision(FLOATING_POINT_PRECISION);
// 			std::cout << "Time to process a range of " \
// 			<< _elementCount << " elements with std::vector : " \
// 			<< _time  << " us " << std::endl;	
// 		}

// 		class InvalidValueException : public std::exception {
// 			public:
// 				virtual const char* what() const throw() {
// 					return (RED "Error: Invalid value detected in the input.\n" RESET);
// 				}
// 		};
// };

// template<typename T>
// void mergeInsertSort(T& numbers) {
	
// }

// class PmergeMe {
// 	private:
// 		std::vector<int> _containerV;
// 		std::list<int> _containerL;
// 		int	_elementCount;
// 		double _timeV;
// 		double _timeL;

// 		PmergeMe(void);

// 		bool isValidValue(char*);

// 	public:
// 		PmergeMe(char** input);
// 		~PmergeMe(void);
// 		PmergeMe(PmergeMe const& src);
// 		PmergeMe& operator=(PmergeMe const& rhs);

// 		void sort(void);
// 		void printNumbers(void);
// 		void printTime(void);

// 		class InvalidValueException : public std::exception {
// 			public:
// 				virtual const char* what() const throw();
// 		};
// };
