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
	std::cout << "\033[36m===== Test 1: newZombie =====\033[0m" << std::endl;	
	Zombie* zombie = Zombie::newZombie( "Eddie" );
	delete zombie;
}

void	test2( void )
{
	std::cout << std::endl;
	std::cout << "\033[36m===== Test 2: newZombie & announce =====\033[0m" << std::endl;	
	Zombie* zombie = Zombie::newZombie( "Sophia" );
	zombie->announce();
	delete zombie;
}

void	test3( void )
{
	std::cout << std::endl;
	std::cout << "\033[36m===== Test 3: randomChump =====\033[0m" << std::endl;	
	Zombie::randomChump( "Shaun" );
}

int	main( void )
{
	test1();
	test2();
	test3();
	return (0);
}
