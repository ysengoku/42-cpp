/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:39:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 11:30:35 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Replacer.hpp"


int	main( int argc, char **argv )
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./Replace filename s1 s2" << std::endl;
		return (1);
	}
	std::string	const filename = argv[1];
	std::string const s1 = argv[2];
	std::string const s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "s1 is empty." << std::endl;
		return (1);
	}
	if (s2.empty())
	{
		std::cerr << "s2 is empty." << std::endl;
		return (1);
	}
	Replacer replacer(filename, s1, s2);
	if (replacer.replaceText() == 1)
		return (1);
	return (0);
}

// test1 ---> s1: world, s2: universe
// test2 ---> s1: fox, s2: cat
// test3 ---> s1: be, s2: exist
