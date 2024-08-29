/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:19 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/29 13:55:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./btc <file name>" << std::endl;
		return (1);
	}
	BitcoinExcange btc(argv[1]);
	btc.exchange();

	// BitcoinExcange copy1(btc);
	// copy1.exchange();

	// BitcoinExcange copy2;
	// copy2 = btc;
	// copy2.exchange();
	return (0);
}
