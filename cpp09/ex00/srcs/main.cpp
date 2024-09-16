/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:19 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/16 11:42:33 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <file name>" << std::endl;
		return (1);
	}
	try {
		BitcoinExcange btc(argv[1]);
		btc.exchange();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// BitcoinExcange copy1(btc);
	// copy1.exchange();

	// BitcoinExcange copy2;
	// copy2 = btc;
	// copy2.exchange();
	return (0);
}
