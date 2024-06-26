/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:47 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 16:01:48 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

HumanA::HumanA( std::string name, Weapon& weapon )
	: _name(name), _weapon(weapon)
{
	std::cout << "\033[34m" << this->_name << " entered." << "\033[0m" << std::endl;
	return ;
}

HumanA::~HumanA( void )
{
	std::cout << "\033[34m" << this->_name << " has left." << "\033[0m" << std::endl;
	return ;
}

/*============================================================================*/
/*       Public functions                                                     */
/*============================================================================*/

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}
