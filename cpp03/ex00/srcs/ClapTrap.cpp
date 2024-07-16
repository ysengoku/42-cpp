/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/16 15:32:51 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLACKI "\e[0;90m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

ClapTrap::ClapTrap( void )
	: _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << YELLOW << "ClapTrap: Default constructor called." << RESET << std::endl;
}

ClapTrap::ClapTrap( std::string Name )
	: _name(Name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << YELLOW << "ClapTrap " << this->_name << ": Constructor called." << std::endl;
	std::cout << "> " << this->_name << "'s initial status: " \
	<< "Hit points: " << this->_hitPoints \
	<< " | Energy points: " << this->_energyPoints \
	<< " | Attack damage: " << this->_attackDamage << RESET << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src )
{
	std::cout << YELLOW << "ClapTrap: Copy constructor called." << RESET << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << YELLOW << "ClapTrap: Destructor called." << std::endl;
	std::cout << "> " << this->_name << "'s final status: " \
	<< "Hit points: " << this->_hitPoints \
	<< " | Energy points: " << this->_energyPoints << RESET << std::endl;
}

/*============================================================================*/
/*       Copy assignment operator                                             */
/*============================================================================*/

ClapTrap	&ClapTrap::operator=( const ClapTrap& rhs )
{
	std::cout << YELLOW << "ClapTrap: Copy assignement operator called." << RESET << std::endl;
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
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		--this->_energyPoints;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << \
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

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints >= amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << this->_name << " has taken " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		--this->_energyPoints;
		std::cout << this->_name << " repaires itself, getting " \
		<< amount << " points back." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
		std::cout << RED << this->_name \
		<< " has no energy points left. Cannot repaire itself." << RESET << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << RED << this->_name \
		<< " has no hit points left. Cannot repaire itself." << RESET << std::endl;
}

void	ClapTrap::printStatus( void )
{
	std::cout << BLACKI << this->_name << "'s current status : Energy points " \
	<< this->_energyPoints << " | Hit points " << this->_hitPoints << RESET << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string	const&	ClapTrap::getName( void )
{
	return (this->_name);
}

unsigned int const&	ClapTrap::getHitPoints( void )
{
	return (this->_hitPoints);
}

unsigned int const&	ClapTrap::getEnergyPoints( void )
{
	return (this->_energyPoints);
}

unsigned int const&	ClapTrap::getAttackDamage( void )
{
	return (this->_attackDamage);
}
