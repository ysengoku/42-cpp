/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:32 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/02 12:35:57 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./RPN \"inverted Polish mathematical expression\"" << std::endl;
		return (1);
	}
	RPN rpn(argv[1]);
	return (0);
}

// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// ./RPN "7 7 * 7 -"
// 42
// ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// ./RPN "(1 + 1)"
// Error