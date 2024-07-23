/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 10:47:11 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Cat::Cat( void )
	: AAnimal("Cat")
{
	std::cout << BLACKI << "Cat: Default constructor called." << RESET << std::endl;
	this->_brain = new Brain();
}

Cat::Cat( const Cat& src )
	: AAnimal(src)
{
	std::cout << BLACKI << "Cat: Copy constructor called." << RESET << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat& Cat::operator=( const Cat& rhs )
{
	std::cout << BLACKI << "Cat: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << BLACKI << "Cat: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Cat::makeSound( void ) const
{
	std::cout << "Meow 🐱" << std::endl;
}

void	Cat::showIdea( unsigned int i ) const
{
	if (i < 100)
		std::cout << this->_brain->getIdea(i) << std::endl;
}

void	Cat::showAllIdeas( void ) const
{
	for (int i = 0; i < 100; i++)
		std::cout << this->_brain->getIdea(i) << std::endl;
}

void	Cat::setIdeaToBrain( std::string const& idea, unsigned int i ) const
{
	if (i < 100)
		this->_brain->setIdea(idea, i);
}
