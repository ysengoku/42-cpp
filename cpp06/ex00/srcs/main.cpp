/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:38:30 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/01 13:01:35 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch(const ScalarConverter::InvalidInputException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		return (0);
	}
	std::cout << "Usage: ./convert <value to convert>" << std::endl;
	return (1);
}
