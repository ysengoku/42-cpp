/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:00:58 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 16:13:48 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class Weapon
{
	public:
		/* Constructor */
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
