/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:09:57 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 15:15:03 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde( int N, std::string name )
{
	if (N < 1)
		return (NULL);
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		new (horde + i) Zombie(name);
	return (horde);
}