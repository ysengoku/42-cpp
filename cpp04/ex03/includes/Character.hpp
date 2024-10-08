/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:15:13 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 12:08:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		AMateria*	_tmpInventory[4];

	public:
		Character( void );
		Character( std::string const& name );
		Character( Character const& src );
		Character& operator=( Character const& rhs );
		~Character( void );

		std::string const&	getName( void ) const;

		void				equip( AMateria *m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );
};

# endif
