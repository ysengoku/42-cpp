/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 16:36:32 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	test1( void )
{
	std::cout << CYAN << "====== TEST1 ======" << RESET << std::endl;
	ClapTrap*	clapTrap = new ClapTrap( "Clappy" );
	
	clapTrap->attack("Trappy");
	clapTrap->printStatus();
	clapTrap->takeDamage(5);
	clapTrap->printStatus();
	clapTrap->beRepaired(2);
	clapTrap->printStatus();
	delete clapTrap;
}

void	test2( void )
{
	std::cout << std::endl << CYAN << "====== TEST2 ======" << RESET << std::endl;
	ClapTrap*	clapTrap = new ClapTrap( "Clappy" );
	
	for(int i = 0; i < 5; i++)
	{
		clapTrap->attack("Trappy");
		clapTrap->printStatus();
		clapTrap->takeDamage(5);
		clapTrap->printStatus();
		clapTrap->beRepaired(2);
		clapTrap->printStatus();
	}
	clapTrap->beRepaired(2);
	clapTrap->printStatus();
	delete clapTrap;
}

int	main()
{
	test1();
	test2();
	return (0);
}
