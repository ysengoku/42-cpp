/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:15:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 08:51:09 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Character::Character( void )
{
	std::cout << BLACKI << "Character: Default constructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
		this->_tmpInventory[i] = 0;
	}
}

Character::Character( std::string const& name )
	: _name(name)
{
	std::cout << BLACKI << "Character: Constructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
		this->_tmpInventory[i] = 0;
	}
}

Character::Character( Character const& src )
{
	std::cout << BLACKI << "Character: Copy constructor called." << RESET << std::endl;
	*this = src;
}

Character&	Character::operator=( Character const& rhs )
{
	std::cout << BLACKI << "Character: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			this->_inventory[i] = 0;
			delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			this->_tmpInventory[i] = 0;
			delete this->_tmpInventory[i];
			if (rhs._tmpInventory[i])
				this->_tmpInventory[i] = rhs._tmpInventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character( void )
{
	std::cout << BLACKI << "Character: Destructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		delete this->_tmpInventory[i];
	}
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	Character::getName( void ) const
{
	return (this->_name);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Character::equip( AMateria *m )
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << YELLOW << m->getType() << " has been successfully equipped." << RESET << std::endl;
			return ;
		}
	}
}

void	Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		std::string	tmp = this->_inventory[idx]->getType();
		for (int i = 0; i < 4; i++)
		{
			if (!this->_tmpInventory[i])
			{
				this->_tmpInventory[i] = this->_inventory[idx];
				this->_inventory[idx] = 0;
				std::cout << YELLOW << tmp << " has been successfully unequipped." << RESET << std::endl;
				return ;
			}
		}
		std::cout << RED << "Cannot unequip "<< tmp << ". Temporary storage is full." << RESET << std::endl;
	}
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
