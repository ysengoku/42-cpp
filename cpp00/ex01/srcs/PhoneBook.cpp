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

#include "PhoneBook.hpp"

/*===== Constructor & Destructor =============================================*/

PhoneBook::PhoneBook( void )
{	
	std::cout << CYAN << "================================" << RESET << std::endl;
	std::cout << BGWHITE << BLACK  << "   Welcome to Mini PhoneBook    " << RESET << std::endl;
	std::cout << CYAN << "================================" << RESET << std::endl;
	std::cout << "Save a new contact -> " << GREEN << "ADD" << RESET << std::endl;
	std::cout << "Display contact detail -> " << GREEN << "SEARCH" << RESET << std::endl;
	std::cout << "Quit ->" << GREEN << "EXIT" << RESET << std::endl;
	this->_count = 0;
	return;
}

PhoneBook::~PhoneBook( void )
{	
	std::cout << "Thank you for using Mini Phone Book. See you soon 👋" << std::endl;
	return;
}

/*===== Public functions =====================================================*/

void	PhoneBook::addContact( void )
{
	int i = 0;

	if (this->_count == 7)
		this->_replaceContact(&i);
	else
		i = this->_count;
	this->_contacts[i].setFirstName();
	this->_contacts[i].setLastName();
	this->_contacts[i].setNickname();
	this->_contacts[i].setPhone();
	this->_contacts[i].setDarkestSecret();
	this->_count++;
}

void	PhoneBook::displayContact( void )
{
	this->_displayContactTable();
}

/*===== Private functions ====================================================*/

void	PhoneBook::_replaceContact( int *i )
{
	while (*i++ < 6)
		this->_contacts[*i - 1] = this->_contacts[*i];
}

void	PhoneBook::_displayContactTable( void )
{
	std::cout << std::endl;
	//std::cout << "----------------------------------------------" << std::endl;
	std::cout << BGWHITE << BLACK <<" Index | First name | Last name  |  Nickname  " << RESET << std::endl;
	//std::cout << "----------------------------------------------" << std::endl;
	for (int i = 0; i < this->_count; i++)
	{
		std::cout << "   " << i << "   |";
		if (this->_contacts[i].getFirstName().length() > 10)
			std::cout << " " << this->_contacts[i].getFirstName() << " |";
	}
}

//void	PhoneBook::_displayContactDetail( void )
//{
//
//}