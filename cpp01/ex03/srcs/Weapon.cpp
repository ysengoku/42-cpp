/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:06:39 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 16:12:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

Weapon::Weapon( std::string weaponType )
{
	this->setType(weaponType);
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

/*============================================================================*/
/*       Member functions                                                     */
/*============================================================================*/

std::string const&	Weapon::getType( void )
{
	return (this->_type);
}

void	Weapon::setType( std::string weaponType )
{
	this->_type = weaponType;
	return ;
}
