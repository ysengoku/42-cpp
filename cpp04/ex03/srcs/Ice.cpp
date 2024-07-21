/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:23:24 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 12:19:26 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Ice::Ice( void )
	: AMateria("ice")
{
	std::cout << BLACKI << "Ice: Default constructor called." << RESET << std::endl;
}

Ice::Ice( Ice const& src )
	: AMateria(src)
{
	std::cout << BLACKI << "Ice: Copy constructor called." << RESET << std::endl;
}

Ice&	Ice::operator=( Ice const& rhs )
{
	std::cout << BLACKI << "Ice: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Ice::~Ice( void )
{
	std::cout << BLACKI << "Ice: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice*	Ice::clone( void ) const
{
	return new Ice(*this);
}
