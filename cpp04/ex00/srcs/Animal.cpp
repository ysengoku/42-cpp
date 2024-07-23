/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:39 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 08:54:01 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Animal::Animal( void )
{
	std::cout << BLACKI << "Animal: Default constructor called." << RESET << std::endl;
}

Animal::Animal( const std::string type )
	: type(type)
{
	std::cout << BLACKI << "Animal: Constructor called." << RESET << std::endl;
}

Animal::Animal( const Animal& src )
{
	std::cout << BLACKI << "Animal: Copy constructor called." << RESET << std::endl;
	*this = src;
}

Animal&	Animal::operator=( const Animal& rhs)
{
	std::cout << BLACKI << "Animal: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << BLACKI << "Animal: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Animal::makeSound( void ) const
{
	std::cout << ".........." << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	Animal::getType( void ) const
{
	return (this->type);
}
