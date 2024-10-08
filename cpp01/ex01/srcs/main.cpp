/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:20:41 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/28 09:38:36 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main( int argc, char **argv )
{
	if (argc != 3)
	{
		std::cout << "Usage: ./zombieHorde (number of zombies) (name)" << std::endl;
		return (1);
	}
	int N = std::atoi(argv[1]);
	Zombie *horde = zombieHorde( N, argv[2] );
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
}
