/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:58:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/28 08:57:55 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

Harl::Harl( void )
{
	std::cout << "\033[33m" << "Harl: Constructor called" << "\033[0m" <<std::endl;
	return ;
}
Harl::~Harl( void )
{
	std::cout << "\033[33m" << "Harl: Destructor called" << "\033[0m" <<std::endl;
	return ;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Harl::complaintsFilter( std::string level )
{
	int			levelIndex;
	void		(Harl::*functions[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::switchOff};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (levelIndex = 0; levelIndex < 4; levelIndex++)
	{
		if (level == levels[levelIndex])
			break ;
	}
	switch (levelIndex)
	{
		case 0:
			for (int i = 0; i < 4; i++)
				(this->*(functions[i]))();
			break ;
		case 1:
			for (int i = 1; i < 4; i++)
				(this->*(functions[i]))();					
			break ;
		case 2:
			for (int i = 2; i < 4; i++)
				(this->*(functions[i]))();
			break ;
		case 3:
			(this->*(functions[3]))();
			break ;
		default:
			(this->*(functions[4]))();
			break ;
	}
}

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

void	Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl \
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "\
	<< std::endl << "I really do!" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO]" << std::endl \
	<< "I cannot believe adding extra bacon costs more money. "\
	<< std::endl << "You didn't put enough bacon in my burger! " << std::endl \
	<< "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl \
	<< "I think I deserve to have some extra bacon for free. "\
	<< std::endl << "I've been coming for years whereas you started working here since last month." \
	<< std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl \
	<< "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::switchOff( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
