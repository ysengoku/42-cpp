/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:07:24 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/18 13:53:11 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Brain::Brain( void )
{
	std::cout << BLACKI << "Brain: Default constructor called." << RESET << std::endl;
}

Brain::Brain( const Brain& src )
{
	std::cout << BLACKI << "Brain: Copy constructor called." << RESET << std::endl;
	*this = src;
}

Brain& Brain::operator=( const Brain& rhs )
{
	std::cout << BLACKI << "Brain: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << BLACKI << "Brain: Destructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Accessors                                                            */
/*============================================================================*/

void	Brain::setIdea( const std::string idea, unsigned int i )
{
	if (i < IDEAS_COUNT)
		this->_ideas[i] = idea; 
}

std::string const&	Brain::getIdea( unsigned int i )
{
	if (i >= IDEAS_COUNT)
	{
		std::cerr << RED << "Error: Invalid index." << RESET << std::endl;
		return (this->_ideas[0]);
	}
	return (this->_ideas[i]);
}

const std::string*	Brain::getIdeas( void )
{
	return (this->_ideas);
}