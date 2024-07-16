/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/16 08:12:01 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		/* Constructor */
		ClapTrap( void );
		ClapTrap( std::string Name );
		ClapTrap( std::string Name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		/* Copy constructor */
		ClapTrap( const ClapTrap& src );
		/* Copy assignment operator */
		ClapTrap& operator=( const ClapTrap& rhs );
		/* Destructor */
		~ClapTrap( void );

		/* Public member functions */
		void virtual	attack( const std::string& target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );
		void			printStatus( void );
		/* Accesors */
		unsigned int const&	getHitPoints( void );
		unsigned int const&	getEnergyPoints( void );
		unsigned int const&	getAttackDamage( void );
		
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif

/*
public: accessible from outside the class
private: not accessible from outside the class
protected: not accessible from outside the class but accessible in inherited classes.
*/