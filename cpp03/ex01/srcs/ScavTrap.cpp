/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:43 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 17:16:43 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

ScavTrap::ScavTrap( void )
{
	std::cout << YELLOW << "ScavTrap: Default constructor called." << RESET << std::endl;
}

ScavTrap::ScavTrap( std::string Name )
{
	this->_name = Name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap " << this->_name << " appeared." << std::endl;
	std::cout << "== His initial status ==" << std::endl \
	<< "> Hit points: " << this->_hitPoints << std::endl \
	<< "> Energy points: " << this->_energyPoints << std::endl \
	<< "> Attack damage: " << this->_attackDamage << RESET << std::endl << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& src )
{
	std::cout << YELLOW << "The copy of ScavTrap " << this->_name << " was created." << RESET << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << std::endl << YELLOW << "ScavTrap " << this->_name << " disappeared." << std::endl;
	std::cout << "== His final status ==" << std::endl \
	<< "> Hit points: " << this->_hitPoints << std::endl \
	<< "> Energy points: " << this->_energyPoints << std::endl \
	<< "> Attack damage: " << this->_attackDamage << RESET << std::endl;

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

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
