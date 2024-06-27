/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 08:24:32 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

HumanB::HumanB( std::string name )
	: _name(name), _weapon(0)
{
	std::cout << "\033[33m" << this->_name << " entered." << "\033[0m" << std::endl;
	return ;
}

HumanB::~HumanB( void )
{
	std::cout << "\033[33m" << this->_name << " has left." << "\033[0m" << std::endl;
	return ;
}

/*============================================================================*/
/*       Public functions                                                     */
/*============================================================================*/

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}

void	HumanB::attack( void )
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " tries to attack without success. He has no weapon." << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}
