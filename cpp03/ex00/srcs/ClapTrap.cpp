/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 08:12:18 by yusengok         ###   ########.fr       */
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
	std::cout << YELLOW << "ClapTrap: Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src )
{
	std::cout << YELLOW << "ClapTrap: Copy constructor called" << RESET << std::endl;
	if (this != &src)
		*this = src;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << YELLOW << "ClapTrap: Destructor called" << RESET << std::endl;
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

void	attack( const std::string& target )
{
	
}

void	takeDamage( unsigned int amount )
{
	
}

void	beRepaired( unsigned int amount )
{}
