/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:39 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/18 14:45:21 by yusengok         ###   ########.fr       */
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
	: _type(type)
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
		this->_type = rhs._type;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << BLACKI << "Animal: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	Animal::getType( void ) const
{
	return (this->_type);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Animal::makeSound( void ) const
{
	std::cout << "Buzz" << std::endl;
}

void	Animal::voiceIdea( void ) const {}

void	Animal::replaceIdea( const std::string idea, unsigned int i ) const
{
	(void)idea;
	(void)i;
}
