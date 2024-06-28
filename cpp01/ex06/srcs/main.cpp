/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:58:09 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/28 08:50:10 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter (level)" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complaintsFilter(argv[1]);
	return (0);
}
