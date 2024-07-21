/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:23:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 12:19:32 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Cure::Cure( void )
	: AMateria("cure")
{
	std::cout << BLACKI << "Cure: Default constructor called." << RESET << std::endl;
}

Cure::Cure( Cure const& src )
	: AMateria(src)
{
	std::cout << BLACKI << "Cure: Copy constructor called." << RESET << std::endl;
}

Cure& Cure::operator=( Cure const& rhs )
{
	std::cout << BLACKI << "Cure: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs )
		this->_type = rhs._type;
	return (*this);
}

Cure::~Cure( void )
{
	std::cout << BLACKI << "Cure: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure*	Cure::clone( void ) const
{
	return new Cure(*this);
}
