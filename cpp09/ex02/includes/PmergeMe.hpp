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

# define FLOATING_POINT_PRECISION 5

// template<template <typename, typename> class Container>
// std::ostream& operator<<(std::ostream& os, const Container< int, std::allocator<int> >& container);

class PmergeMe {
	public:
		PmergeMe(char** input);
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
		std::vector<int> _containerV;
		std::deque<int> _containerD;
		size_t	_size;
		// int _straggler;
		double _timeV;
		double _timeD;

		PmergeMe(void);
		
		bool isValidValue(char*);
		void printTime(std::string const& containerType, double time);

		template<template <typename, typename> class Container>
		double mergeInsertSort(Container< int, std::allocator<int> >& container) {
			int straggler = -1;
			struct timeval begin, end;
			gettimeofday(&begin, 0);

			for (int i = 1; _input[i]; ++i) {
				if (!isValidValue(_input[i]))
					throw InvalidValueException();
				container.push_back(atoi(_input[i]));
			}
			_size = container.size();
			if (_size % 2 != 0) {
				straggler = container.back();
				container.pop_back();
			}

			/* Step1 */
			typename Container< int, std::allocator<int> >::iterator it = container.begin();
			typename Container< int, std::allocator<int> >::iterator ite = container.end();
			while (it != ite) {
				if (*it > *(it + 1))
					std::swap(*it, *(it + 1));
				std::advance(it, 2);
			}
			// std::cout << container << std::endl;
			Container< int, std::allocator<int> > tmp1;

			if (straggler > 0)
				container.push_back(straggler); /// temporary

			gettimeofday(&end, 0);
			long sec = end.tv_sec - begin.tv_sec;
			long usec = end.tv_usec - begin.tv_usec;
			return (sec * 1000000 + usec);
		}		
};

template<template <typename, typename> class Container>
std::ostream& operator<<(std::ostream& os, const Container< int, std::allocator<int> >& container) {
	typename Container< int, std::allocator<int> >::const_iterator it = container.begin();
	typename Container< int, std::allocator<int> >::const_iterator ite = container.end();
	while (it != ite - 1) {
		os << *it << ' ';
		++it;
	}
	os << *it;
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
