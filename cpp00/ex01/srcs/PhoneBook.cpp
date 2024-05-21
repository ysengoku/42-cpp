/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:58:32 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/21 16:10:48 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*===== Constructor & Destructor =============================================*/

PhoneBook::PhoneBook( void ) : _count(0)
{	
	PhoneBook::_printMenu();
	return;
}

PhoneBook::~PhoneBook( void )
{	
	std::cout << "Thank you for using Mini PhoneBook. See you soon ✋" << std::endl;
	return;
}

/*===== Public functions =====================================================*/

void	PhoneBook::addContact( void )
{
	int i = 0;

	std::cout << std::endl << MAGENTA << "▶︎▶︎▶︎ Adding new contact" << RESET << std::endl;
	if (this->_count == 8)
		i = this->_replaceContact();
	else
		i = this->_count;
	this->_contacts[i].setFirstName();
	this->_contacts[i].setLastName();
	this->_contacts[i].setNickname();
	this->_contacts[i].setPhone();
	this->_contacts[i].setDarkestSecret();
	if (this->_count < 8)
		this->_count++;
}

void	PhoneBook::displayContact( void )
{
	if (this->_count == 0)
	{
		std::cout << "You have no contacts yet." << std::endl;
		std::cout << "To add a contact, type " << GREEN << "ADD" << RESET << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << MAGENTA << "▶︎▶︎▶︎ Displaying your contact list" << RESET << std::endl;
		this->_displayContactTable();
		this->_displayContactDetail();
	}
}

/*===== Private functions ====================================================*/

void	PhoneBook::_printMenu( void ) const
{
	std::cout << "================================" << std::endl;
	std::cout << BGWHITE << BLACK  << "   Welcome to Mini PhoneBook    " << RESET << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "Save a new contact -> " << GREEN << "ADD" << RESET << std::endl;
	std::cout << "Display contact detail -> " << GREEN << "SEARCH" << RESET << std::endl;
	std::cout << "Quit ->" << GREEN << "EXIT" << RESET << std::endl << std::endl;
}

int	PhoneBook::_replaceContact( void )
{
	std::cout << YELLOW << "The oldest contact will be replaced by new one." << RESET << std::endl;
	for (int i = 0; i < 7; i++)
		this->_contacts[i] = this->_contacts[i + 1];
	return (7);
}

void	PhoneBook::_displayContactTable( void )
{
	std::cout << std::endl;
	std::cout << BGWHITE << BLACK <<"     Index|First name| Last name|  Nickname" << RESET << std::endl;
	for (int i = 0; i < this->_count; i++)
	{
		std::cout << "         " << i << "|";
		this->_printTableElement(this->_contacts[i].getFirstName());
		std::cout << "|";
		this->_printTableElement(this->_contacts[i].getLastName());
		std::cout << "|";
		this->_printTableElement(this->_contacts[i].getNickname());
		std::cout << std::endl << "----------+----------+----------+----------" <<std::endl;
	}
}

void	PhoneBook::_printTableElement( std::string element )
{
	std::string	str;

	if (element.length() > 9)
		str = element.substr(0, 9) + ".";
	else
		str = element;
	std::cout << std::setw(10) << str;
}

void	PhoneBook::_displayContactDetail( void )
{
	std::string	input;
	int			i = -1;

	std::cout << std::endl;
	while (true)
	{
		std::cout << "Choose index >> ";
		std::getline(std::cin, input);
		if (input.empty())
			continue ;
		if (input.length() > 1 || input[0] < '0' || input[0] > '7')
			std::cout << YELLOW << "Invalid index. Please retry." << RESET << std::endl;
		else
		{
			i =  input[0] - '0';
			if (i > this->_count - 1)
				std::cout << YELLOW << "Index " << i << " is empty. Please retry." << RESET << std::endl;
			else
				break ;
		}
	}
	std::cout << std::endl;
	std::cout << BGWHITE << BLACK " Index " << input[0] << " " << RESET << std::endl;
	std::cout << "First name     : " << this->_contacts[i].getFirstName() << std::endl;
	std::cout << "Last name      : " << this->_contacts[i].getLastName() << std::endl;
	std::cout << "Nickname       : " << this->_contacts[i].getNickname() << std::endl;
	std::cout << "Phone number   : " << this->_contacts[i].getPhone() << std::endl;
	std::cout << "Darkest secret : " << this->_contacts[i].getSecret() << std::endl;
	std::cout << std::endl;
}
