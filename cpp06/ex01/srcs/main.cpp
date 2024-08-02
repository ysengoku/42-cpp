/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:22:53 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/02 09:26:55 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( void )
{
	Data		data(42, "Robert", 5.4, true);
	uintptr_t	serialized;
	Data		*deserialized;
	
	std::cout << CYAN << "--- Original ------" << RESET << std::endl
	<< "pointer: " << &data << std::endl
	<< data << std::endl;

	serialized = Serializer::serialize(&data);
	deserialized = Serializer::deserialize(serialized);

	std::cout << CYAN << "--- After deserializing ------" << RESET << std::endl
	<< "pointer: " << deserialized << std::endl
	<< *deserialized << std::endl;
	if (&data == deserialized)
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	else
		std::cout << RED << "FAILURE" << RESET << std::endl;
}
