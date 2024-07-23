/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:44 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 08:54:01 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Dog::Dog( void )
	: Animal("Dog")
{
	std::cout << BLACKI << "Dog: Default constructor called." << RESET << std::endl;
}

Dog::Dog( const Dog& src )
	: Animal(src)
{
	std::cout << BLACKI << "Dog: Copy constructor called." << RESET << std::endl;
	*this = src;
}

Dog& Dog::operator=( const Dog& rhs )
{
	std::cout << BLACKI << "Dog: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << BLACKI << "Dog: Destructor called." << RESET << std::endl;	
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Dog::makeSound( void ) const
{
	std::cout << "Woof woof 🐶" << std::endl;
}
