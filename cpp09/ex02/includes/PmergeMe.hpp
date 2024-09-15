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

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GREY "\e[0;90m"
# define RESET "\033[0m"

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

		/*----- Functions overloading: Vector  -----*/
		void sortByPair(std::vector<int>& seq, size_t blockSize, size_t blockCount);
		void splitAndBinaryInsert(std::vector<int>& seq, size_t blockSize, size_t blockCount);
		void insertPendElements(v_iter_pair_container& mainChain, v_iter_pair_container& pend, int pendSize, size_t blockSize);
		void findBinarySearchRange(v_iter_pair_container& mainChain, v_iter_pair_container& pend, v_iter_pair_container::iterator& start, v_iter_pair_container::iterator& end, v_iter_pair_container::iterator& lastInserted, int target, size_t blockSize);
		void rebuildSequence(std::vector<int>& seq, v_iter_pair_container& mainChain, size_t blockSize, size_t blockCount);

		/*----- Functions overloading: List  -----*/
		void sortByPair(std::list<int>& seq, size_t blockSize, size_t blockCount);
		void splitAndBinaryInsert(std::list<int>& seq, size_t blockSize, size_t blockCount);
		void insertPendElements(l_iter_pair_container& mainChain, l_iter_pair_container& pend, int pendSize, size_t blockSize);
		void findBinarySearchRange(l_iter_pair_container& mainChain, l_iter_pair_container& pend, l_iter_pair_container::iterator& start, l_iter_pair_container::iterator& end, l_iter_pair_container::iterator& lastInserted, int target, size_t blockSize);
		void rebuildSequence(std::list<int>& seq, l_iter_pair_container& mainChain, size_t blockSize, size_t blockCount);

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

		template<class Container>
		void mergeInsertionSort(Container& sequence, size_t const blockSize, size_t const blockCount) {
			if (blockCount < 1)
				return;
			sortByPair(sequence, blockSize, blockCount);
			mergeInsertionSort(sequence, blockSize * 2, blockCount / 2);
			splitAndBinaryInsert(sequence, blockSize, blockCount);
		};

		template<typename Container, typename IterPairContainer>
		void pushToMainChain(Container const& sequence, IterPairContainer& mainChain, IterPairContainer& pend, size_t blockSize, size_t blockCount) {
			typename Container::const_iterator it = sequence.begin();
			std::advance(it, blockSize - 1);
			#ifdef DEBUG
				std::cout << GREEN "\n===== < Push to Main chain > Block size: " << blockSize << "  Block count: " << blockCount << " =====" RESET << std::endl;
			#endif
			for (size_t i = 0; i < blockCount - blockCount % 2; ++i) {
				if (i == 0)	
					mainChain.push_back(std::make_pair(*it, it));
				else if (i == 1)
					mainChain.push_back(std::make_pair(*it, it));
				else if (i % 2 != 0)
					mainChain.push_back(std::make_pair(*it, it));
				else
					pend.push_back(std::make_pair(*it, it));
				#ifdef DEBUG
					std::cout << "Pushed " << *it << std::endl;
					std::cout << "Main chain: ";
					for (typename IterPairContainer::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
						std::cout << it->first << ' ';
					std::cout << std::endl;
					std::cout << "Pend: ";
					if (!pend.empty()) {
						for (typename IterPairContainer::iterator it = pend.begin(); it != pend.end(); ++it)
							std::cout << it->first << ' ';
						std::cout << std::endl;
					}
					std::cout << std::endl << std::endl;
				#endif
				std::advance(it, blockSize);
			}
			if (blockCount % 2 != 0) {
				pend.push_back(std::make_pair(*it, it));
				#ifdef DEBUG
					std::cout << "Pushed " << *it << std::endl;
				#endif
			}
			#ifdef DEBUG
				std::cout << "Main chain: ";
				for (typename IterPairContainer::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
					std::cout << it->first << ' ';
				std::cout << std::endl;
				std::cout << "Pend: ";
				if (!pend.empty()) {
					for (typename IterPairContainer::iterator it = pend.begin(); it != pend.end(); ++it)
						std::cout << it->first << ' ';
					std::cout << std::endl;
				}
				std::cout << std::endl;
			#endif
		};

		template<typename Container, typename Iterator, typename Pair>
		Iterator binarySearchInsert(Container& mainChain, Pair& toInsert, Iterator& start, Iterator& end) {
			while (start != end) {
				Iterator middle = start;
				std::advance(middle, std::distance(start, end) / 2);
				if (toInsert.first < middle->first)
					end = middle;
				else {
					start = middle;
					++start;
				}
			}
			Iterator insertPos =  mainChain.insert(start, toInsert);
			#ifdef DEBUG
				std::cout << "Main chain ";
				for (Iterator it = mainChain.begin(); it != mainChain.end(); ++it)
				std::cout << it->first << ' ';
				std::cout << std::endl << std::endl;
			#endif
			return (insertPos);
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

#endif
