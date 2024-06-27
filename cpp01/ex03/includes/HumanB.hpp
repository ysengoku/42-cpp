/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:28 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 09:09:12 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class	HumanB
{
	public:
		/* Constructor */
		HumanB( std::string name);
		/* Destructor */
		~HumanB( void );
		/* Member functions */
		void	setWeapon( Weapon &weapon );
		void	attack( void );
	
	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif