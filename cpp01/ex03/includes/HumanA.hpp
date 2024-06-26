/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:08 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 16:05:43 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class	HumanA
{
	public:
		/* Constructor */
		HumanA( std::string name, Weapon& weapon );
		/* Destructor */
		~HumanA( void );
		/* Member functions */
		void	attack( void );
	
	private:
		std::string	_name;
		Weapon&		_weapon;
};

#endif