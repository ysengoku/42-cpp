/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:33 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/15 15:28:26 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string Name );
		ScavTrap( const ScavTrap& src);
		ScavTrap& operator=( const ScavTrap& rhs );
		~ScavTrap( void );

		void	attack( const std::string& target ) override;
		void	guardGate( void );
};

#endif
