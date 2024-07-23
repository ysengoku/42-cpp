/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:48 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 10:33:45 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

WrongAnimal::WrongAnimal( void )
{
	std::cout << BLACKI << "WrongAnimal: Default constructor called." << RESET << std::endl;	
}

WrongAnimal::WrongAnimal( const std::string type )
	: type(type)
{
	std::cout << BLACKI << "WrongAnimal: Constructor called." << RESET << std::endl;	
}

WrongAnimal::WrongAnimal( const WrongAnimal& src )
{
	std::cout << BLACKI << "WrongAnimal: Copy constructor called." << RESET << std::endl;
	*this = src;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& rhs )
{
	std::cout << BLACKI << "WrongAnimal: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << BLACKI << "WrongAnimal: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "RRRRRRR" << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	WrongAnimal::getType( void ) const
{
	return (this->type);
}
