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

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
	
int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;
	
	std::cout << "Enter command >>>";
	std::cin >> command;
	std::cout << "Command received: " << command << std::endl;
	if (std::string(command) == "ADD")
	{
		std::cout << "First name: ";
		//std::cin >> 
	}

	return 0;
}
