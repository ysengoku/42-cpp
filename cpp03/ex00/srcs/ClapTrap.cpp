/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 13:28:51 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

ClapTrap::ClapTrap( std::string Name )
	: _name(Name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << YELLOW << "ClapTrap " << this->_name << " appeared." << std::endl;
	std::cout << "== His initial status ==" << std::endl \
	<< "Hit points: " << this->_hitPoints << std::endl \
	<< "Energy points: " << this->_energyPoints << std::endl \
	<< "Attack damage: " << this->_attackDamage << RESET << std::endl << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src )
{
	std::cout << YELLOW << "The copy of ClapTrap " << this->_name << " appeared." << RESET << std::endl;
	if (this != &src)
		*this = src;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << std::endl << YELLOW << "ClapTrap " << this->_name << " disappeared." << std::endl;
	std::cout << "== His Final status ==" << std::endl \
	<< "Hit points: " << this->_hitPoints << std::endl \
	<< "Energy points: " << this->_energyPoints << std::endl \
	<< "Attack damage: " << this->_attackDamage << RESET << std::endl;
}

/*============================================================================*/
/*       Copy assignment operator                                             */
/*============================================================================*/

ClapTrap	&ClapTrap::operator=( const ClapTrap& rhs )
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
/*       Public member functions                                              */
/*============================================================================*/

void	ClapTrap::attack( const std::string& target )
{
	if (this->_energyPoints == 0)
		return ;
	// target loses this->_attackDamage hit points
	--this->_energyPoints;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << \
	", causing " << this->_attackDamage << " points of damage!" << std::endl;
	std::cout << "== Current Energy points of " << this->_name << " is " \
	<< this->_energyPoints << " points. ==" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " has taken " \
	<< amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints == 0)
		return ;
	this->_hitPoints += amount;
	--this->_energyPoints;
	std::cout << "ClapTrap " << this->_name << " repaires itself, getting " \
	<< amount << " points back." << std::endl;
	std::cout << "== Current Energy points of " << this->_name << " is " \
	<< this->_energyPoints << " points. ==" << std::endl;
}
