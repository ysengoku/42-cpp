/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/11 16:44:27 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <ctime>

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	constructorCheck( void )
{
	std::cout << CYAN << "====== CONSTRUCTOR CHECK ======" << RESET << std::endl;	
	{
		std::cout << CYAN << " ++ ClapTrap ++ " << RESET << std::endl;
		ClapTrap	a("CLAPPY");
		ClapTrap	b(a);
	}
	{
		std::cout << CYAN << " ++ ScavTrap ++ " << RESET << std::endl;
		ScavTrap	c("SCAPPY");
	}
	{
		std::cout << CYAN << " ++ ScavTrap Copy constructor ++ " << RESET << std::endl;
		ScavTrap	c("SCAPPY");
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
}

int	main()
{
	constructorCheck();
	simpleTest();
	randomTest();
	return (0);
}
