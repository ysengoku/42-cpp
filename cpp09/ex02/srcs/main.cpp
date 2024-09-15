/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:45 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/06 13:07:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2 || !argv[1][0]) {
		std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
		return (1);
	}
	++argv;
	try {
		PmergeMe pmergeme(argv, argc - 1);

		/* Sort with vector */
		pmergeme.sortSequence(pmergeme.getVector());
		std::cout << "After: " << pmergeme.getVector() << std::endl;
		pmergeme.printTime(VECTOR);

		/* Sort with list */
		pmergeme.sortSequence(pmergeme.getList());
		pmergeme.printTime(LIST);

		#ifdef CHECK
			std::vector<int> vec = pmergeme.getVector();
			std::list<int> lst = pmergeme.getList();
			std::cout << "\n=== Sort Check ===\n";
			std::cout << "vector: ";
			std::is_sorted(vec.begin(), vec.end()) ? std::cout << GREEN << "SUCCESS!!\n" << RESET : std::cout << RED << "FAILED...\n" << RESET;
			std::cout << "list: ";
			std::is_sorted(lst.begin(), lst.end()) ? std::cout << GREEN << "SUCCESS!!\n" << RESET : std::cout << RED << "FAILED...\n" << RESET;
			std::cout << std::endl;
		#endif
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
