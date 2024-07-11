/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/11 15:47:51 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	constructorCheck( void )
{
	std::cout << CYAN << "====== CONSTRUCTOR CHECK ======" << RESET << std::endl;	
	ClapTrap a( "Test" );
	ClapTrap b(a);
}

void	simpleTest( void )
{
	std::cout << std::endl << CYAN << "====== SIMPLE TEST ======" << RESET << std::endl;
	ClapTrap	clapTrap( "Clappy" );
	
	clapTrap.attack("Trappy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(2);
}

void	randomTest( void )
{
	std::cout << std::endl << CYAN << "====== RANDOM TEST ======" << RESET << std::endl;
	ClapTrap	clapTrap( "Clappy" );
	int			randomNum;

	std::srand(std::time(0));
	while (clapTrap.getEnergyPoints() > 0 && clapTrap.getHitPoints() > 0)
	{
		randomNum = std::rand() % 3;
		switch(randomNum)
		{
			case 0:
				clapTrap.attack("Trappy");
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
}

int	main()
{
	constructorCheck();
	simpleTest();
	randomTest();
	return (0);
}
