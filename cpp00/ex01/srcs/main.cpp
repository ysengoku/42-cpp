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

	while (std::string(input) != "EXIT")
	{
		std::cout << CYAN << "Enter command " << "▶︎▶︎▶︎ " << RESET;
		std::cin >> input;
	
		if (std::string(input) == "ADD")
			phonebook.addContact();
		else if (std::string(input) == "SEARCH")
			phonebook.displayContact();
		else if (std::string(input) == "EXIT")
			std::cout << RED << "Deleting phonebook data..." << RESET << std::endl;
		else
			std::cout << RED << "[Error] " << RESET << "Invalid command" << std::endl;
	}
	return 0;
}
