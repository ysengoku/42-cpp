/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/15 09:36:34 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>
#include <ctime>

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	constructorCheck( void )
{
	std::cout << CYAN << "====== CONSTRUCTOR CHECK ======" << RESET << std::endl;	
	{
		std::cout << CYAN << "++ ClapTrap ++ " << RESET << std::endl;
		ClapTrap	a("CLAPPY");
		ClapTrap	b(a);
	}
	{
		std::cout << CYAN << "++ FragTrap ++ " << RESET << std::endl;
		FragTrap	c("FRAPPY");
		std::cout << CYAN << "++ FragTrap Copy constructor ++ " << RESET << std::endl;
		FragTrap	d(c);
	}
}

void	simpleTest( void )
{
	std::cout << std::endl << CYAN << "====== SIMPLE TEST ======" << RESET << std::endl;
	{
		std::cout << CYAN << " ++ ClapTrap ++ " << RESET << std::endl;
		ClapTrap	clapTrap("CLAPPY");
		clapTrap.attack("Trappy");
		clapTrap.takeDamage(5);
		clapTrap.beRepaired(2);
	}
	{
		std::cout << CYAN << " ++ ScavTrap ++ " << RESET << std::endl;
		ScavTrap	scavTrap("SCAPPY");	
		scavTrap.attack("TRAPPY");
		scavTrap.takeDamage(5);
		scavTrap.beRepaired(2);
		scavTrap.guardGate();
	}
	{
		std::cout << CYAN << " ++ FrapTrap ++ " << RESET << std::endl;
		FragTrap	fragTrap("FRAPPY");
		fragTrap.takeDamage(5);
		fragTrap.beRepaired(2);
		fragTrap.highFivesGuys();
	}
}

void	randomTest( void )
{
	std::cout << std::endl << CYAN << "====== RANDOM TEST ======" << RESET << std::endl;
	FragTrap	fragTrap("FRAPPY");
	int			randomNum;
	
	std::srand(std::time(0));
	while (fragTrap.getEnergyPoints() > 0 && fragTrap.getHitPoints() > 0)
	{
		randomNum = std::rand() % 3;
		switch (randomNum)
		{
			case 0:
				fragTrap.highFivesGuys();
				break;
			case 1:
				fragTrap.takeDamage(15);
				break;
			case 2:
				fragTrap.beRepaired(10);
				break;
			default:
				break;
		}
		fragTrap.printStatus();
	}
	fragTrap.beRepaired(10);
}

void	engergyPointsTest( void )
{
	std::cout << std::endl << CYAN << "====== ENERGY POINTS TEST ======" << RESET << std::endl;
	FragTrap	fragTrap("FRAPPY");	

	for (int i = 0; i <= 100; i++)
		fragTrap.beRepaired(1);
}

int	main()
{
	constructorCheck();
	simpleTest();
	randomTest();
	engergyPointsTest();
	return (0);
}
