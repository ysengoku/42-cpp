/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/15 14:58:10 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

FragTrap::FragTrap( void )
	: ClapTrap("No name", 100, 100, 30)
{
	std::cout << YELLOW << "FragTrap: Default constructor called." << RESET << std::endl;
}

// FragTrap::FragTrap( std::string Name )
// {
// 	this->_name = Name;
// 	this->_hitPoints = 100;
// 	this->_energyPoints = 100;
// 	this->_attackDamage = 30;
// 	std::cout << YELLOW << "FragTrap " << this->_name << " appeared." << std::endl;
// 	std::cout << "> " << this->_name << "'s initial status: " 
// 	<< "Hit points: " << this->_hitPoints 
// 	<< " | Energy points: " << this->_energyPoints 
// 	<< " | Attack damage: " << this->_attackDamage << RESET << std::endl;
// }

FragTrap::FragTrap( std::string Name )
	: ClapTrap(Name, 100, 100, 30)
{
	std::cout << YELLOW << "FragTrap " << this->_name << " appeared." << std::endl;
	std::cout << "> " << this->_name << "'s initial status: " 
	<< "Hit points: " << this->_hitPoints 
	<< " | Energy points: " << this->_energyPoints 
	<< " | Attack damage: " << this->_attackDamage << RESET << std::endl;
}

FragTrap::FragTrap( const FragTrap& src )
	: ClapTrap(src)
{
	std::cout << YELLOW << "The copy of FragTrap " << this->_name << " was created." << RESET << std::endl;
	*this = src;
}

FragTrap::~FragTrap( void )
{
	std::cout << YELLOW << "FragTrap " << this->_name << " disappeared." << std::endl;
	std::cout << "> " << this->_name << "'s final status: " \
	<< "Hit points: " << this->_hitPoints \
	<< " | Energy points: " << this->_energyPoints << RESET << std::endl;
}

/*============================================================================*/
/*       Copy assignment operator                                             */
/*============================================================================*/

FragTrap& FragTrap::operator=( const FragTrap& rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

/*============================================================================*/
/*      Member function                                                       */
/*============================================================================*/

void	FragTrap::highFivesGuys( void )
{
	std::cout << "🙌 HIGH FIVE from FragTrap " << this->_name << std::endl;
}
