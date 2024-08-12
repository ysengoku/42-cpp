/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:41:39 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/12 17:03:45 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

void emptyArray(void) {
	std::cout << CYAN << "====== Empty array ======" << RESET << std::endl;
	Array<int> array;
	// std::cout << "Array content: " << array[0] << std::endl;
}

int main(void) {
	emptyArray();
	return (0);
}