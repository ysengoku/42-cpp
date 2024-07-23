/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:51 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 08:54:01 by yusengok         ###   ########.fr       */
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
		this->_brain = rhs._brain; // Shallow copy
	}
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << BLACKI << "WrongCat: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	WrongCat::makeSound( void ) const
{
	std::cout << "Roarrrrr 🦁" << std::endl;
}

void	WrongCat::showIdeas( void ) const
{
	for (int i = 0; i < IDEAS_COUNT; i++)
		std::cout << this->_brain->getIdea(i) << std::endl;
}

void	WrongCat::updateIdea( std::string const& idea, unsigned int i ) const
{
	if (i < IDEAS_COUNT)
		this->_brain->setIdea(idea, i);
}
