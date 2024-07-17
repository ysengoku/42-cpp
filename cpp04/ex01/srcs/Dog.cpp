/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:44 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/17 15:29:47 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Dog::Dog( void )
	: Animal("Dog")
{
	std::cout << BLACKI << "Dog: Default constructor called." << RESET << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog& src )
	: Animal(src)
{
	std::cout << BLACKI << "Dog: Copy constructor called." << RESET << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog& Dog::operator=( const Dog& rhs )
{
	std::cout << BLACKI << "Dog: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);	
	}
	return (*this);
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout << BLACKI << "Dog: Destructor called." << RESET << std::endl;	
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Dog::makeSound( void ) const
{
	std::cout << "Woof woof 🐶" << std::endl;
}
