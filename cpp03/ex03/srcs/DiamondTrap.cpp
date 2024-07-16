/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:39:00 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/16 09:37:57 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

DiamondTrap::DiamondTrap( void )
{
	std::cout << MAGENTA << "DiamondTrap: Default constructor called." << RESET << std::endl;
}

DiamondTrap::DiamondTrap( std::string Name )
	: ClapTrap(Name + "_clap_name"), ScavTrap(Name), FragTrap(Name)
{
	this->_name = Name;
	// this->_hitPoints = FragTrap::_hitPoints;
	// this->_energyPoints = ScavTrap::_energyPoints;
	// this->_attackDamage = FragTrap::_attackDamage;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << MAGENTA << "DiamondTrap " << this->_name << ": Constructor called." << std::endl;
	std::cout << "> " << this->_name << "'s initial status: " \
	<< "Hit points: " << this->_hitPoints \
	<< " | Energy points: " << this->_energyPoints \
	<< " | Attack damage: " << this->_attackDamage << RESET << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& src )
	: ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << MAGENTA << "The copy of DiamondTrap " << this->_name << " was created." << RESET << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << MAGENTA << "DiamondTrap " << this->_name << " disappeared." << std::endl;
	std::cout << "> " << this->_name << "'s final status: " \
	<< "Hit points: " << this->_hitPoints \
	<< " | Energy points: " << this->_energyPoints \
	<< " | Attack damage: " << this->_attackDamage << RESET << std::endl;
}

/*============================================================================*/
/*       Copy assignment operator                                             */
/*============================================================================*/

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

/*============================================================================*/
/*      Overload function                                                     */
/*============================================================================*/

void	DiamondTrap::attack( std::string const & target )
{
	ScavTrap::attack(target);
}

/*============================================================================*/
/*      Member function                                                       */
/*============================================================================*/

void	DiamondTrap::whoAmI( void )
{
	std::cout << "🤖 I'm " << this->_name << ". My ClapTrap name is " << this->ClapTrap::_name << "." << std::endl;
}
