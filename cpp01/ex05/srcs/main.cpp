/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:39:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 16:47:47 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

void	randomComplaints(Harl* harl, int numberOfComplaints)
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

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	randomComplaints(&harl, 6);
	return (0);
}
