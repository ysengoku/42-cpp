/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:15:24 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/22 09:17:31 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

MateriaSource::MateriaSource( void )
{
	std::cout << BLACKI << "MateriaSource: Default constructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = 0;
}

MateriaSource::MateriaSource( MateriaSource const& src )
{
	std::cout << BLACKI << "MateriaSource: Copy constructor called." << RESET << std::endl;
	*this = src;
}

MateriaSource& MateriaSource::operator=( MateriaSource const& rhs )
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_materias[i];
			this->_materias[i] = 0;
			if (rhs._materias[i])
				this->_materias[i] = rhs._materias[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	std::cout << BLACKI << "MateriaSource: Destructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_materias[i];
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	MateriaSource::learnMateria( AMateria* src )
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = src;
			return ;
		}
	}
	std::cout << RED << "Materia source is full." << RESET << std::endl;
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	std::cout << "Materia \'" << type << "\' was not found." << std::endl;
	return (0);
}
