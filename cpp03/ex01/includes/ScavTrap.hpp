/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:33 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/15 14:26:19 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp" 

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string Name );
		ScavTrap( const ScavTrap& src);
		ScavTrap& operator=( const ScavTrap& rhs );
		~ScavTrap( void );

		void	attack( const std::string& target );
		void	guardGate( void );
};

#endif

/*
public: accessible from outside the class
private: not accessible from outside the class
protected: not accessible from outside the class but accessible in inherited classes.
*/