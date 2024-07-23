/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:44 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 10:47:49 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Dog::Dog( void )
	: AAnimal("Dog")
{
	std::cout << BLACKI << "Dog: Default constructor called." << RESET << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog& src )
	: AAnimal(src)
{
	std::cout << BLACKI << "Dog: Copy constructor called." << RESET << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog& Dog::operator=( const Dog& rhs )
{
	std::cout << BLACKI << "Dog: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
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

void	Dog::showIdea( unsigned int i ) const
{
	if (i < 100)
		std::cout << this->_brain->getIdea(i) << std::endl;
}

void	Dog::showAllIdeas( void ) const
{
	for (int i = 0; i < 100; i++)
	{
		if (!this->_brain->getIdea(i).empty())
			std::cout << this->_brain->getIdea(i) << std::endl;
	}
}

void	Dog::setIdeaToBrain( std::string const& idea, unsigned int i ) const
{
	if (i < 100)
		this->_brain->setIdea(idea, i);
}
