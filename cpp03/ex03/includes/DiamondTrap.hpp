/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:37:53 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/16 11:04:58 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap( std::string Name );
		DiamondTrap( const DiamondTrap& src );
		DiamondTrap& operator=(const DiamondTrap& rhs);
		~DiamondTrap();

		void	attack( std::string const& target );
		void	whoAmI( void );

	private:
		std::string	_name;
		ScavTrap	scavTrap;
		FragTrap	fragTrap;
};

#endif