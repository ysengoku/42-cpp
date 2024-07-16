/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/16 12:58:44 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>

#define CYAN "\033[36m"
#define BLACKI "\e[0;90m"
#define RESET "\033[0m"

void	constructorCheck( void )
{
	std::cout << CYAN << "====== CONSTRUCTOR CHECK ======" << RESET << std::endl;		
	ClapTrap a("CLAPPY");
	std::cout << BLACKI << "--------------------------------------------------" << RESET << std::endl;
	ClapTrap b(a);
	std::cout << BLACKI << "--------------------------------------------------" << RESET << std::endl;
	ClapTrap c;
	c = b;
}

void	simpleTest( void )
{
	std::cout << std::endl << CYAN << "====== SIMPLE TEST ======" << RESET << std::endl;
	ClapTrap	clapTrap("CLAPPY");
	
	clapTrap.attack("TRAPPY");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(2);
}

void	randomTest( void )
{
	std::cout << std::endl << CYAN << "====== RANDOM TEST ======" << RESET << std::endl;
	ClapTrap	clapTrap("CLAPPY");
	int			randomNum;

	std::srand(std::time(0));
	while (clapTrap.getEnergyPoints() > 0 && clapTrap.getHitPoints() > 0)
	{
		randomNum = std::rand() % 3;
		switch(randomNum)
		{
			case 0:
				clapTrap.attack("TRAPPY");
				break;
			case 1:
				clapTrap.takeDamage(5);
				break;
			case 2:
				clapTrap.beRepaired(3);
			default:
				break;
		}
		clapTrap.printStatus();
	}
	clapTrap.attack("TRAPPY");
	clapTrap.beRepaired(3);
}

void	energyPointsTest( void )
{
	std::cout << std::endl << CYAN << "====== ENERGY POINTS TEST ======" << RESET << std::endl;
	ClapTrap	clapTrap("CLAPPY");	

	for (int i = 0; i <= 10; i++)
	{
		if (i % 2 == 0)
			clapTrap.beRepaired(1);
		else
			clapTrap.attack("TRAPPY");
	}
}

int	main()
{
	constructorCheck();
	simpleTest();
	randomTest();
	energyPointsTest();
	return (0);
}
