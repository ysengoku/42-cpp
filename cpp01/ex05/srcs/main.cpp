/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:54:13 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/28 08:58:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

void	randomTest(Harl* harl, int numberOfComplaints)
{	
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			levelsCount = 4;
	int			randomIndex;

	std::srand(std::time(0));
	for (int i = 0; i < numberOfComplaints; i++)
	{
		randomIndex = std::rand() % levelsCount;
		(*harl).complain(levels[randomIndex]);
	}
}

int		main( void )
{
	Harl		harl;

	std::cout << "\033[36m======= Sequence tests =======\033[0m" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	std::cout << "\033[36m======= Random tests =======\033[0m" << std::endl;
	randomTest(&harl, 8);
	return (0);
}
