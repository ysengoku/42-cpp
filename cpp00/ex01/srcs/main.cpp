/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:12:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/22 12:06:12 by yusengok         ###   ########.fr       */
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
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << YELLOW << "Reached the end of file. Exiting the program..." \
			<< RESET << std::endl;
			// std::exit(0);
			return (0);
		}
		if (input.empty())
			continue ;
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.displayContact();
		else if (input == "EXIT")
		{
			std::cout << RED << "Deleting phonebook data..." << RESET << std::endl;
			std::cout << "Thank you for using Mini PhoneBook. See you soon ✋" << std::endl;
			break ;
		}
		else
			std::cout << RED << "[Error] " << RESET << "Invalid command" << std::endl;
	}
	return (0);
}
