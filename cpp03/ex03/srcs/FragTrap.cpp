/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/16 10:20:09 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

FragTrap::FragTrap( void )
	: ClapTrap("Default", 100, 100, 30)
{
	std::cout << YELLOW << "FragTrap: Default constructor called." << RESET << std::endl;
}

FragTrap::FragTrap( std::string Name )
	: ClapTrap(Name, 100, 100, 30)
{
	std::cout << YELLOW << "FragTrap: Constructor called." << std::endl;
}

FragTrap::FragTrap( const FragTrap& src )
	: ClapTrap(src)
{
	std::cout << YELLOW << "FragTrap: Copy constructor called." << RESET << std::endl;
	*this = src;
}

FragTrap::~FragTrap( void )
{
	std::cout << YELLOW << "FragTrap : Destructor called." << std::endl;
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
	std::cout << "🙌 HIGH FIVE from " << this->_name << std::endl;
}
