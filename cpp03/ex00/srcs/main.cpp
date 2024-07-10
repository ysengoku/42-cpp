/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 13:23:34 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	test1( void )
{
	ClapTrap*	clapTrap = new ClapTrap( "Clappy" );
	
	clapTrap->attack( "Trappy" );
	clapTrap->takeDamage(3);
	clapTrap->beRepaired(2);
	delete clapTrap;
}

int	main()
{
	test1();
	return (0);
}