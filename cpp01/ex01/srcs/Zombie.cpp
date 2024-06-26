/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:09:18 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 15:23:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

Zombie::Zombie ( void )
{
	std::cout << "\033[33m" << "A zombie appeared." << "\033[0m" << std::endl;
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

// Zombie*	Zombie::newZombie( std::string name )
// {
// 	return ( new Zombie( name ));
// }

// void	Zombie::randomChump( std::string name )
// {
// 	Zombie* zombie = newZombie(name);
// 	zombie->announce();
// 	delete zombie;
// 	return ;
// }
