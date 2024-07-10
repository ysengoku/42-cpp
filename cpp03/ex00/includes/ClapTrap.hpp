/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 08:05:37 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		/* Constructor*/
		ClapTrap( std::string Name );	
		/* Copy constructor */
		ClapTrap( const ClapTrap& src );
		/* Copy assignment operator */
		ClapTrap& operator=( const ClapTrap& rhs );
		/* Destructor */
		~ClapTrap( void );

		/* Public member functions */
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
		
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif