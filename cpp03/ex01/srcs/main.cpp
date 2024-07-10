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

#include "ScavTrap.hpp"
#include "ScavTrap.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	test1( void )
{
	std::cout << CYAN << "====== TEST1 ======" << RESET << std::endl;
	ScavTrap*	scavTrap = new ScavTrap( "Scappy" );
	
	scavTrap->attack("Trappy");
	scavTrap->printStatus();
	scavTrap->takeDamage(5);
	scavTrap->printStatus();
	scavTrap->beRepaired(2);
	scavTrap->printStatus();
	scavTrap->guardGate();
	delete scavTrap;
}

void	test2( void )
{
	std::cout << std::endl << CYAN << "====== TEST2 ======" << RESET << std::endl;
	ScavTrap*	scavTrap = new ScavTrap( "Scappy" );
	
	for(int i = 0; i < 5; i++)
	{
		scavTrap->attack("Trappy");
		scavTrap->printStatus();
		scavTrap->takeDamage(5);
		scavTrap->printStatus();
		scavTrap->guardGate();
		scavTrap->beRepaired(2);
		scavTrap->printStatus();
	}
	scavTrap->guardGate();
	scavTrap->beRepaired(2);
	scavTrap->printStatus();
	delete scavTrap;
}

int	main()
{
	test1();
	test2();
	return (0);
}
