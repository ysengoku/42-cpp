/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/16 15:21:07 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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
		std::cout << CYAN << "++ ScavTrap ++ " << RESET << std::endl;
		ScavTrap	c("SCAPPY");
		std::cout << CYAN << "++ ScavTrap Copy constructor ++ " << RESET << std::endl;
		ScavTrap	d(c);
	}
}

void	simpleTest( void )
{
	std::cout << std::endl << CYAN << "====== SIMPLE TEST ======" << RESET << std::endl;
	{
		ClapTrap	clapTrap( "Clappy" );
		clapTrap.attack("Trappy");
		clapTrap.takeDamage(5);
		clapTrap.beRepaired(2);
	}
	{
		ScavTrap	scavTrap("SCAPPY");	
		scavTrap.attack("TRAPPY");
		scavTrap.takeDamage(5);
		scavTrap.beRepaired(2);
		scavTrap.guardGate();
	}
}

void	randomTest( void )
{
	std::cout << std::endl << CYAN << "====== RANDOM TEST ======" << RESET << std::endl;
	ScavTrap	scavTrap("SCAPPY");
	int			randomNum;
	
	std::srand(std::time(0));
	while (scavTrap.getEnergyPoints() > 0 && scavTrap.getHitPoints() > 0)
	{
		randomNum = std::rand() % 3;
		switch (randomNum)
		{
			case 0:
				scavTrap.attack("TRAPPY");
				break;
			case 1:
				scavTrap.takeDamage(15);
				break;
			case 2:
				scavTrap.beRepaired(10);
				break;
			default:
				break;
		}
		scavTrap.printStatus();
	}
	scavTrap.attack("TRAPPY");
	scavTrap.beRepaired(10);
}

void	energyPointsTest( void )
{
	std::cout << std::endl << CYAN << "====== ENERGY POINTS TEST ======" << RESET << std::endl;
	ScavTrap	scavTrap("SCAPPY");	

	for (int i = 0; i <= 50; i++)
	{
		if (i % 2 == 0)
			scavTrap.beRepaired(1);
		else
			scavTrap.attack("TRAPPY");
	}
}

void	battleTest( void )
{
	std::cout << std::endl << CYAN << "====== BATTLE TEST ======" << RESET << std::endl;
	ScavTrap	scavTrap1("SCAPPY");
	ScavTrap	scavTrap2("TRAPPY");
	
	int			randomNum;
	
	std::srand(std::time(0));
	while (scavTrap1.getEnergyPoints() > 0 && scavTrap1.getHitPoints() > 0 \
	&& scavTrap2.getEnergyPoints() > 0 && scavTrap2.getHitPoints() > 0)
	{
		randomNum = std::rand() % 4;
		switch (randomNum)
		{
			case 0:
				scavTrap1.attack(scavTrap2.getName());
				scavTrap2.takeDamage(scavTrap1.getAttackDamage());
				break;
			case 1:
				scavTrap2.attack(scavTrap1.getName());
				scavTrap1.takeDamage(scavTrap2.getAttackDamage());
				break;
			case 2:
				scavTrap1.beRepaired(20);
				break;
			case 3:
				scavTrap2.beRepaired(25);
				break;
			default:
				break;
		}
	}
	if (scavTrap1.getEnergyPoints() == 0 || scavTrap1.getHitPoints() == 0)
		std::cout << "🎉🎉🎉 " << scavTrap2.getName() << " is winner 🎉🎉🎉" << std::endl;
	else
		std::cout << "🎉🎉🎉 " << scavTrap1.getName() << " is winner 🎉🎉🎉" << std::endl;
}

int	main()
{
	constructorCheck();
	simpleTest();
	randomTest();
	energyPointsTest();
	battleTest();
	return (0);
}
