/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 08:54:01 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Cat::Cat( void )
	: Animal("Cat")
{
	std::cout << BLACKI << "Cat: Default constructor called." << RESET << std::endl;
}

Cat::Cat( const Cat& src )
	: Animal(src)
{
	std::cout << BLACKI << "Cat: Copy constructor called." << RESET << std::endl;
	*this = src;
}

Cat& Cat::operator=( const Cat& rhs )
{
	std::cout << BLACKI << "Cat: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << BLACKI << "Cat: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Cat::makeSound( void ) const
{
	std::cout << "Meow 🐱" << std::endl;
}
