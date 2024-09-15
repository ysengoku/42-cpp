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

# include <vector>
# include <list>
# include <iostream>
# include <iomanip>
# include <string>
# include <algorithm>
# include <cstdlib>
# include <climits>
# include <cerrno>
# include <ctime>

# define FLOATING_POINT_PRECISION 5
# define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000.0)
# define VECTOR "std::vector"
# define LIST "std::list"

class PmergeMe {
	public:
		typedef std::pair<int, std::vector<int>::const_iterator> v_iter_pair;
		typedef std::pair<int, std::list<int>::const_iterator> l_iter_pair;
		typedef std::vector<v_iter_pair> v_iter_pair_container;
		typedef std::list<l_iter_pair> l_iter_pair_container;

		PmergeMe(char** input, size_t size);
		~PmergeMe(void);
		PmergeMe(PmergeMe const& src);
		PmergeMe& operator=(PmergeMe const& rhs);

		template<typename Container>
		void sortSequence(Container& container) {
			clock_t start = clock();
			for (int i = 0; _input[i]; ++i) {
				if (!isValidValue(_input[i]))
					throw InvalidValueException();
				container.push_back(atoi(_input[i]));
			}
			if (!checkDuplicate(container))
				throw DuplicateFoundException();
			mergeInsertionSort(container, 1, container.size());
			_time = (clock() - start) / CLOCKS_PER_MS;
		}
		
		std::vector<int>& getVector(void);
		std::list<int>& getList(void);
		void printTime(std::string const& containerType);

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
		double _time;
		std::vector<int> _vec;
		std::list<int> _list;

		PmergeMe(void);
		
		bool isValidValue(char const*);
		int jacobsthalNumber(size_t n);

		void mergeInsertionSort(std::vector<int>& sequence, size_t const blockeSize, size_t const blockCount);
		void mergeInsertionSort(std::list<int>& sequence, size_t const blockSize, size_t const blockCount);

		/*----- Vector  -----*/
		void sortByPair(std::vector<int>& seq, size_t blockSize, size_t blockCount);	
		void splitAndBinaryInsert(std::vector<int>& seq, size_t blockSize, size_t blockCount);
		void pushToMainChain(std::vector<int> const& sequence, v_iter_pair_container& mainChain, v_iter_pair_container& pend, size_t blockSize, size_t blockCount);
		void insertPendElements(v_iter_pair_container& mainChain, v_iter_pair_container& pend, int pendSize, size_t blockSize);
		void findBinarySearchRange(v_iter_pair_container& mainChain, v_iter_pair_container& pend, v_iter_pair_container::iterator& start, v_iter_pair_container::iterator& end, v_iter_pair_container::iterator& lastInserted, int target, size_t blockSize);
		v_iter_pair_container::iterator binarySearchInsert(v_iter_pair_container& mainChain, v_iter_pair& toInsert, v_iter_pair_container::iterator& start, v_iter_pair_container::iterator& end);
		void rebuildSequence(std::vector<int>& seq, v_iter_pair_container& mainChain, size_t blockSize, size_t blockCount);

		/*----- List  -----*/

		/*----- Templates -----*/
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
		};
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
