/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:51 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/17 12:45:17 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

WrongCat::WrongCat( void )
	: WrongAnimal("WrongCat")
{
	std::cout << BLACKI << "WrongCat: Default constructor called." << std::endl;
}

WrongCat::WrongCat( const WrongCat& src )
	: WrongAnimal(src)
{
	std::cout << BLACKI << "WrongCat: Copy constructor called."	<< std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=( const WrongCat& rhs )
{
	std::cout << BLACKI << "WrongCat: Copy assignment operator called."	<< std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << BLACKI << "WrongCat: Destructor called."	<< std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	WrongCat::makeSound( void ) const
{
	std::cout << "Roarrrrr 🦁" << std::endl;
}
