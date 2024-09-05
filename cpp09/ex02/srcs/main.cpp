/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:45 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/05 08:06:23 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
		return (1);
	}
	try {
		PmergeMe pmergeme(argv);
		pmergeme.sort();
	}
	catch (std::exception &e) {
		std::cerr << e.what();
	}
	return (0);
}

// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// This command in argument generates 3,000 random numbers between 1 and 100,000,
// and then outputs these numbers in a single line, separated by spaces. 

// int main(int argc, char** argv) {
// 	if (argc == 1) {
// 		std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
// 		return (1);
// 	}
// 	try {
// 		PmergeMe< std::vector > pmergeme(argv);
// 		std::cout << "Before:  ";
// 		pmergeme.printNumbers();
// 		pmergeme.sort();
// 		std::cout << "After:   ";
// 		pmergeme.printNumbers();
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << e.what();
// 	}
// 	return (0);
// }
