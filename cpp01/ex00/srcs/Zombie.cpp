/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:41:10 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/25 15:48:46 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

Zombie::Zombie( void )
	: _name("")
{
	return ;
}

Zombie::~Zombie( void )
{
	return ;
}

/*============================================================================*/
/*       Public functions                                                     */
/*============================================================================*/


/*============================================================================*/
/*       Private functions                                                    */
/*============================================================================*/

void	Zombie::announce( void )
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}