/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/11 14:47:41 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <ctime>

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	simpleTest( void )
{
	std::cout << CYAN << "====== SIMPLE TEST ======" << RESET << std::endl;
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

void	randomTest( void )
{
	ScavTrap*	scavTrap = new ScavTrap( "Scappy" );
	int	randomNum;
	
	std::cout << std::endl << CYAN << "====== TEST RANDOM ======" << RESET << std::endl;
	std::srand(std::time(0));
	while (scavTrap->getEnergyPoints() > 0 && scavTrap->getHitPoints() > 0)
	{
		randomNum = std::rand() % 3;
		switch (randomNum)
		{
			case 0:
				scavTrap->attack("Trappy");
				break;
			case 1:
				scavTrap->takeDamage(15);
				break;
			case 2:
				scavTrap->beRepaired(10);
				break;
			default:
				break;
		}
		scavTrap->printStatus();
	}
	delete scavTrap;
}

int	main()
{
	simpleTest();
	randomTest();
	return (0);
}
