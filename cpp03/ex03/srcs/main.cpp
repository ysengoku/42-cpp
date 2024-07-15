/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/15 15:15:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <cstdlib>
#include <ctime>

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	constructorCheck( void )
{
	std::cout << CYAN << "====== CONSTRUCTOR CHECK ======" << RESET << std::endl;	
	{
		std::cout << CYAN << "++ Constructor ++ " << RESET << std::endl;
		DiamondTrap	a("DIAMOPPY");
	}
	{
		std::cout << CYAN << "++ Copy constructor ++ " << RESET << std::endl;
		DiamondTrap	a("DIAMOPPY");
		DiamondTrap	b(a);
	}
}

void	simpleTest( void )
{
	std::cout << std::endl << CYAN << "====== SIMPLE TEST ======" << RESET << std::endl;
	DiamondTrap	diamondTrap("DIAMOPPY");
	diamondTrap.takeDamage(5);
	diamondTrap.printStatus();
	diamondTrap.beRepaired(2);
	diamondTrap.printStatus();
	diamondTrap.attack("TRAPPY");
	diamondTrap.printStatus();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
	diamondTrap.printStatus();
}

void	randomTest( void )
{
	std::cout << std::endl << CYAN << "====== RANDOM TEST ======" << RESET << std::endl;
	DiamondTrap	diamondTrap("DIAMOPPY");
	int			randomNum;
	
	std::srand(std::time(0));
	while (diamondTrap.getEnergyPoints() > 0 && diamondTrap.getHitPoints() > 0)
	{
		randomNum = std::rand() % 5;
		switch (randomNum)
		{
			case 0:
				diamondTrap.attack("TRAPPY");
				break;
			case 1:
				diamondTrap.highFivesGuys();
				break;
			case 2:
				diamondTrap.takeDamage(15);
				break;
			case 3:
				diamondTrap.beRepaired(10);
				break;
			case 4:
				diamondTrap.whoAmI();
			default:
				break;
		}
		diamondTrap.printStatus();
	}
	diamondTrap.beRepaired(10);
}

void	energyPointsTest( void )
{
	std::cout << std::endl << CYAN << "====== ENERGY POINTS TEST ======" << RESET << std::endl;
	DiamondTrap	diamondTrap("DIAMOPPY");	

	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0)
			diamondTrap.attack("TRAPPY");
		else
			diamondTrap.beRepaired(1);
		if (diamondTrap.getEnergyPoints() == 0)
			break ;
	}
	diamondTrap.attack("TRAPPY");
}

int	main()
{
	constructorCheck();
	simpleTest();
	randomTest();
	energyPointsTest();
	return (0);
}
