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
	PmergeMe pmergeme(argv, argc - 1);
	// try {
	 pmergeme.pmergeme();
	// } catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	return (0);
}

// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// This command in argument generates 3,000 random numbers between 1 and 100,000,
// and then outputs these numbers in a single line, separated by spaces. 
