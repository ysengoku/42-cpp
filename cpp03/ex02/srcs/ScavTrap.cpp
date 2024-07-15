/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:43 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/15 15:05:54 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

ScavTrap::ScavTrap( void )
{
	std::cout << YELLOW << "ScavTrap: Default constructor called." << RESET << std::endl;
}

// ScavTrap::ScavTrap( std::string Name )
// {
// 	this->_name = Name;
// 	this->_hitPoints = 100;
// 	this->_energyPoints = 50;
// 	this->_attackDamage = 20;
// 	std::cout << YELLOW << "ScavTrap " << this->_name << " appeared." << std::endl;
// 	std::cout << "> " << this->_name << "'s initial status: " \
// 	<< "Hit points: " << this->_hitPoints \
// 	<< " | Energy points: " << this->_energyPoints \
// 	<< " | Attack damage: " << this->_attackDamage << RESET << std::endl;
// }

ScavTrap::ScavTrap( std::string Name )
	: ClapTrap(Name, 100, 50, 20)
{
	std::cout << YELLOW << "ScavTrap " << this->_name << " appeared." << std::endl;
	std::cout << "> " << this->_name << "'s initial status: " \
	<< "Hit points: " << this->_hitPoints \
	<< " | Energy points: " << this->_energyPoints \
	<< " | Attack damage: " << this->_attackDamage << RESET << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& src )
	: ClapTrap(src)
{
	std::cout << YELLOW << "The copy of ScavTrap " << this->_name << " was created." << RESET << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << YELLOW << "ScavTrap " << this->_name << " disappeared." << std::endl;
	std::cout << "> " << this->_name << "'s final status: " \
	<< "Hit points: " << this->_hitPoints \
	<< " | Energy points: " << this->_energyPoints << RESET << std::endl;
}

/*============================================================================*/
/*       Copy assignment operator                                             */
/*============================================================================*/

ScavTrap& ScavTrap::operator=( const ScavTrap& rhs )
{
	if (this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage	= rhs._attackDamage;
	}
	return (*this);
}

/*============================================================================*/
/*      Member function                                                       */
/*============================================================================*/

void	ScavTrap::attack( const std::string& target )
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		--this->_energyPoints;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attackDamage << " points of damage!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
		std::cout << RED << this->_name \
		<< " has no energy points left. Cannot attack." << RESET << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << RED << this->_name \
		<< " has no hit points left. Cannot attack." << RESET << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
