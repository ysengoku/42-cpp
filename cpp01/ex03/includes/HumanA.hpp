/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:08 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 09:10:12 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

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