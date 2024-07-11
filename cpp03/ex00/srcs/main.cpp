/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/11 14:44:10 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	simpleTest( void )
{
	std::cout << CYAN << "====== SIMPLE TEST ======" << RESET << std::endl;
	ClapTrap*	clapTrap = new ClapTrap( "Clappy" );
	
	clapTrap->attack("Trappy");
	clapTrap->printStatus();
	clapTrap->takeDamage(5);
	clapTrap->printStatus();
	clapTrap->beRepaired(2);
	clapTrap->printStatus();
	delete clapTrap;
}

void	randomTest( void )
{
	ClapTrap*	clapTrap = new ClapTrap( "Clappy" );
	int	randomNum;

	std::cout << std::endl << CYAN << "====== TEST2 ======" << RESET << std::endl;
	std::srand(std::time(0));
	while (clapTrap->getEnergyPoints() > 0 && clapTrap->getHitPoints() > 0)
	{
		randomNum = std::rand() % 3;
		switch(randomNum)
		{
			case 0:
				clapTrap->attack("Trappy");
				break;
			case 1:
				clapTrap->takeDamage(5);
				break;
			case 2:
				clapTrap->beRepaired(3);
			default:
				break;
		}
		clapTrap->printStatus();
	}
	delete clapTrap;
}

int	main()
{
	simpleTest();
	randomTest();
	return (0);
}
