/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:41:10 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 14:22:16 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

Zombie::Zombie ( void )
{
	std::cout << "\033[33m" << " A zombie appeared." << "\033[0m" << std::endl;
	return ;
}

Zombie::Zombie ( std::string name )
	: _name(name)
{
	std::cout << "\033[33m" << this->_name << " appeared." << "\033[0m" << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << "\033[33m" << this->_name << " vanished." << "\033[0m" << std::endl;
	return ;
}

/*============================================================================*/
/*       Public functions                                                     */
/*============================================================================*/

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
