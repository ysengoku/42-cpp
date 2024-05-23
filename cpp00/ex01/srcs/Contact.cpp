/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:42:08 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/23 14:17:35 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

Contact::Contact( void ) 
	: _firstname(""), 	_lastname(""), _nickname(""), _phone(""), _secret("")
{
	return;
}

Contact::~Contact( void )
{	
	return;
}

/*============================================================================*/
/*       Public functions                                                     */
/*============================================================================*/

void	Contact::setFirstName( void )
{
	while(true)
	{
		this->_firstname = this->_getInput("Enter first name");
		if (this->_firstname.empty())
		{
			std::cout << std::endl << YELLOW << "Reached the End-of-File. Exiting the program..." \
			<< RESET << std::endl;
			std::exit(0);
		}
		if (this->_isValidChar(this->_firstname))
			return ;
	}
}

void	Contact::setLastName( void )
{
	while(true)
	{
		this->_lastname = this->_getInput("Enter last name");
		if (this->_lastname.empty())
		{
			std::cout << std::endl << YELLOW << "Reached the End-of-File. Exiting the program..." \
			<< RESET << std::endl;
			std::exit(0);
		}
		if (this->_isValidChar(this->_lastname))
			return ;
	}
}

void	Contact::setNickname( void )
{
	while(true)
	{
		this->_nickname = this->_getInput("Enter nickname");
		if (this->_nickname.empty())
		{
			std::cout << std::endl << YELLOW << "Reached the End-of-File. Exiting the program..." \
			<< RESET << std::endl;
			std::exit(0);
		}
		if (this->_isValidChar(this->_nickname))
			return ;
	}
}

void	Contact::setPhone( void )
{
	while(true)
	{
		this->_phone = this->_getInput("Enter phone number");
		if (this->_phone.empty())
		{
			std::cout << std::endl << YELLOW << "Reached the End-of-File. Exiting the program..." \
			<< RESET << std::endl;
			std::exit(0);
		}
		if (this->_isNum(this->_phone) == false)
			std::cout << YELLOW << "Invalid input. Phone number field only accepts numerical values." \
			<< RESET << std::endl;
		else if (this->_phone.length() < 4)
			std::cout << YELLOW << "Too few digits. Phone number length must be between 5 and 15 digits" \
			<< RESET << std::endl;
		else
			return ;
	}
}

void	Contact::setDarkestSecret( void )
{
	while(true)
	{
		this->_secret = this->_getInput("Enter darkest secret");
		if (this->_secret.empty())
		{
			std::cout << std::endl << YELLOW << "Reached the End-of-File. Exiting the program..." \
			<< RESET << std::endl;
			std::exit(0);
		}
		if (this->_isValidChar(this->_secret))
			break ;
	}
	std::cout << MAGENTA << "Your new contact has been successfully saved." \
	<< RESET << std::endl << std::endl;
}

std::string	Contact::getFirstName( void ) const
{
	return (this->_firstname);
}

std::string	Contact::getLastName( void ) const
{
	return (this->_lastname);
}

std::string Contact::getNickname( void ) const
{
	return (this->_nickname);
}

std::string Contact::getPhone( void ) const
{
	return (this->_phone);
}

std::string Contact::getSecret( void ) const
{
	return (this->_secret);
}

/*============================================================================*/
/*       Private functions                                                    */
/*============================================================================*/

std::string	Contact::_getInput( std::string prompt )
{
	std::string	input;

	while (true)
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input.length() > 15)
		{
			std::cout << YELLOW << "Input exceeds maximum length. "\
			<< "Please limit it to 15 characters or fewer." \
			<< RESET << std::endl;
			input.clear();
		}
		if (!input.empty())
			break ;
	}
	return (input);
}

bool	Contact::_isNum( std::string input ) const
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool	Contact::_isValidChar(std::string input ) const
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!(isalnum(input[i]) || input[i] == '-'))
		{
			std::cout << YELLOW << "Invalid input. " \
			<< "Enter only alphabetic characters, numbers or hyphens('-')." \
			<< RESET << std::endl;
			return (false);
		}
		if (input[0] == '-' || (input[i] == '-' && !input[i + 1]))
		{
			std::cout << YELLOW << "Hyphen('-') cannot be placed at the beginning nor end." \
			<< RESET << std::endl;			
			return (false);
		}
	}
	return (true);
}
