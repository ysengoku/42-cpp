/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:15:19 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 12:27:41 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

AMateria::AMateria( void )
{
	std::cout << BLACKI << "AMateria: Default constructor called." << RESET << std::endl;
}

AMateria::AMateria( std::string const& type )
	: _type(type)
{
	std::cout << BLACKI << "AMateria: Constructor called." << RESET << std::endl;
}

AMateria::AMateria( AMateria const& src )
{
	std::cout << BLACKI << "AMateria: Copy constructor called." << RESET << std::endl;
	*this = src;
}

AMateria&	AMateria::operator=( AMateria const& rhs )
{
	std::cout << BLACKI << "AMateria: Copy assignment operator called." << RESET << std::endl;
	if ( this != &rhs )
		this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria( void )
{
	std::cout << BLACKI << "AMateria: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const& AMateria::getType( void ) const
{
	return (this->_type);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	AMateria::use( ICharacter& target )
{
	(void)target;
}
