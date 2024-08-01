/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:38:30 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/01 08:17:59 by yusengok         ###   ########.fr       */
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

	// float	num;
	// if (argc != 2)
	// 	return (1);
	// if (static_cast<std::string>(argv[1]) == "nanf")
	// {
	// 	num = std::numeric_limits<float>::quiet_NaN();
	// 	return 0;
	// }
	// if (static_cast<std::string>(argv[1]) == "+inff")
	// {
	// 	num = std::numeric_limits<float>::infinity();
	// 	return 0;
	// }
	// if (static_cast<std::string>(argv[1]) == "-inff")
	// {
	// 	num = -std::numeric_limits<float>::infinity();
	// 	return 0;
	// }
	// errno = 0;
	// char	*end;
	// double	tmp = std::strtod(argv[1], &end);
	// if (*end != 'f' || *(end + 1) != '\0')
	// {
	// 	std::cout << "Not a float" << std::endl;
	// 	return (1);
	// }

	// const float	max_float = std::numeric_limits<float>::max();
    // const float	lowest_float = std::numeric_limits<float>::lowest();
	// std::cout << "max_float: " << max_float << std::endl;
	// std::cout << "lowest_float: " << lowest_float << std::endl;

	// num = static_cast<float>(tmp);
	// if (errno == ERANGE || num > max_float || num < lowest_float)
	// {
	// 	std::cout << "Overflow" << std::endl;
	// 	return 1;
	// }
	// std::cout << "It's float"<< std::endl;
	// return (true);
}


// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan

// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0