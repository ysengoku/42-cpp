/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:38:47 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 15:54:54 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	test1( void )
{
	std::cout << std::endl;
	std::cout << "\033[36m===== Test 1: newZombie (heap) =====\033[0m" << std::endl;	
	Zombie* zombie = newZombie( "Eddie" );
	delete zombie;
}

void	test2( void )
{
	std::cout << std::endl;
	std::cout << "\033[36m===== Test 2: newZombie & announce (heap) =====\033[0m" << std::endl;	
	Zombie* zombie = newZombie( "Sophia" );
	zombie->announce();
	delete zombie;
}

void	test3( void )
{
	std::cout << std::endl;
	std::cout << "\033[36m===== Test 3: randomChump (stack) =====\033[0m" << std::endl;	
	randomChump( "Shaun" );
}

int	main( void )
{
	test1();
	test2();
	test3();
	return (0);
}
