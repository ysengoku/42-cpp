/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:39 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 10:39:34 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

AAnimal::AAnimal( void )
{
	std::cout << BLACKI << "AAnimal: Default constructor called." << RESET << std::endl;
}

AAnimal::AAnimal( const std::string type )
	: _type(type)
{
	std::cout << BLACKI << "AAnimal: Constructor called." << RESET << std::endl;
}

AAnimal::AAnimal( const AAnimal& src )
{
	std::cout << BLACKI << "AAnimal: Copy constructor called." << RESET << std::endl;
	*this = src;
}

AAnimal&	AAnimal::operator=( const AAnimal& rhs)
{
	std::cout << BLACKI << "AAnimal: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AAnimal::~AAnimal( void )
{
	std::cout << BLACKI << "AAnimal: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	AAnimal::getType( void ) const
{
	return (this->_type);
}
