/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:19 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/28 12:36:24 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./btc <file name>" << std::endl;
		return (1);
	}
	BitcoinExcange btc;
	try 
	{
		btc.readDatabase();
	}
	catch (const BitcoinExcange::FileOpenErrorException& e)
	{
		std::cout << "Database file: " << e.what() << std::endl;
	}
	catch (const BitcoinExcange::InvalidValueException& e)
	{
		std::cout << "Database file: " << e.what() << std::endl;
	}
	try
	{
		btc.openInputFile(argv[1]);
	}
	catch(const BitcoinExcange::FileOpenErrorException& e)
	{
		std::cout << "Input file: " << e.what() << std::endl;
	}
	
	
	return (0);
}
