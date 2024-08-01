/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:22:53 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/01 16:12:33 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( void )
{
	Data		*data = new Data();
	uintptr_t	serialized;
	Data		*deserialized;
	
	serialized = Serializer::serialize(data);
	deserialized = Serializer::deserialize(serialized);
	std::cout << "Original pointer: " << data << std::endl
	<< "After deserializing: " << deserialized << std::endl;
	if (data == deserialized)
		std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	else
		std::cout << RED << "FAILURE" << RESET << std::endl;
	delete data;
}
