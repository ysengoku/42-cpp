/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:00:58 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 08:36:11 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		/* Constructor */
		Weapon( void );
		Weapon( std::string weaponType );
		/* Destructor */
		~Weapon( void );
		/* Accesors */
		std::string const&	getType( void );
		void				setType( std::string weaponType );
		
	private:
		std::string	_type;		
};

#endif
