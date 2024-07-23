/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:51 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 11:15:02 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

WrongCat::WrongCat( void )
	: WrongAnimal("WrongCat")
{
	std::cout << BLACKI << "WrongCat: Default constructor called." << RESET << std::endl;
	this->_brain = new Brain();	
}

WrongCat::WrongCat( const WrongCat& src )
	: WrongAnimal(src)
{
	std::cout << BLACKI << "WrongCat: Copy constructor called." << RESET << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=( const WrongCat& rhs )
{
	std::cout << BLACKI << "WrongCat: Copy assignment operator called."	<< RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->_brain = rhs._brain;
	}
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << BLACKI << "WrongCat: Destructor called." << RESET << std::endl;
	delete this->_brain;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	WrongCat::makeSound( void ) const
{
	std::cout << "Roarrrrr 🦁" << std::endl;
}
