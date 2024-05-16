/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:58:32 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/16 15:40:58 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook( void ) {
	
	std::cout << GREEN << "Constructor called" << RESET << std::endl;
	return;
}

PhoneBook::~PhoneBook( void ) {
	
	std::cout << RED << "Destructor called" << RESET << std::endl;
	return;
}

Contact::Contact( void ) {
	
	std::cout << GREEN << "Constructor called" << RESET << std::endl;
	return;
}

Contact::~Contact( void ) {
	
	std::cout << RED << "Destructor called" << RESET << std::endl;
	return;
}
