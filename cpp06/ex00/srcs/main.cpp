/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:38:30 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/31 09:46:48 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	// if (argc == 2)
	// {
	// 	try
	// 	{
	// 		ScalarConverter::convert(argv[1]);
	// 	}
	// 	catch(const ScalarConverter::InvalidInputException& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// 	return (0);
	// }
	// std::cout << "Usage: ./convert <value to convert>" << std::endl;
	// return (1);

	float	num;
	if (argc != 2)
		return (1);
	if (static_cast<std::string>(argv[1]) == "nanf")
	{
		num = std::numeric_limits<float>::quiet_NaN();
		return 0;
	}
	if (static_cast<std::string>(argv[1]) == "+inff")
	{
		num = std::numeric_limits<float>::infinity();
		return 0;
	}
	if (static_cast<std::string>(argv[1]) == "-inff")
	{
		num = -std::numeric_limits<float>::infinity();
		return 0;
	}
	errno = 0;
	char	*end;
	// std::string	argv[1] = argv[1];
	double	tmp = std::strtod(argv[1], &end);
	if (*end != 'f' || *(end + 1) != '\0')
	{
		std::cout << "Not a float" << std::endl;
		return (1);
	}

	const float	max_float = std::numeric_limits<float>::max(); // for overflow check
    const float	lowest_float = std::numeric_limits<float>::lowest(); // for underflow check (negative value)
	// const float denorm_min_float = std::numeric_limits<float>::denorm_min(); // for underflow check (positive value)

	std::cout << "max_float: " << max_float << std::endl;
	std::cout << "lowest_float: " << lowest_float << std::endl;
	// std::cout << "denorm_min_float: " << denorm_min_float << std::endl;

	num = static_cast<float>(tmp); // Convert before check or after ?
	if (errno == ERANGE || num > max_float || num < lowest_float)
	{
		std::cout << "Overflow" << std::endl;
		return 1;
	}
	std::cout << "It's float"<< std::endl;
	return (true);
}
