/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:12:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/16 15:40:49 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
	
int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << CYAN << "Enter command " << "▶︎▶︎▶︎ " << RESET;
//		std::getline(std::cin, input);
		std::cin >> input;
		if (input.empty())
			continue;
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.displayContact();
		else if (input == "EXIT")
		{
			std::cout << RED << "Deleting phonebook data..." << RESET << std::endl;
			break ;
		}
		else
			std::cout << RED << "[Error] " << RESET << "Invalid command" << std::endl;
	}
	return 0;
}
