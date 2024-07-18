/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:44 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/18 14:44:52 by yusengok         ###   ########.fr       */
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
	std::string dogIdeas[IDEAS_COUNT] = {DOG_IDEAS};
	for (int i = 0; i < IDEAS_COUNT; i++)
		this->_brain->setIdea(dogIdeas[i], i);
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

void	Dog::voiceIdea( void ) const
{
	for (int i = 0; i < IDEAS_COUNT; i++)
		std::cout << this->_brain->getIdeas()[i] << std::endl;
}

void	Dog::replaceIdea( const std::string idea, unsigned int i ) const
{
	this->_brain->setIdea(idea, i);
}
