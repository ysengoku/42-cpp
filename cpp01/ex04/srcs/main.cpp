/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:39:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 11:37:49 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

// test1
// ./Replace ./files/test1 world universe
// test2
// ./Replace ./files/test2 fox cat
// test3
// ./Replace ./files/test3 be exist

int	main( int argc, char **argv )
{
	std::string buffer;
	std::string line;
	size_t		position;
	
	if (argc != 4)
	{
		std::cerr << "Usage: ./Replace filename s1 s2" << std::endl;
		return (1);
	}
	std::string	const filename = argv[1];
	std::string const s1 = argv[2];
	std::string const s2 = argv[3];
	std::string const newFile = filename + ".replace";
	std::ifstream inputFile(filename.c_str(), std::ifstream::in);
	if (!inputFile) 
	{
    	std::cerr << "Failed to open file: " << filename << std::endl;
    	return (1);
	}
	while (std::getline(inputFile, line))
		buffer += line + '\n';
	inputFile.close();
	// loop 
	position = buffer.find(s1);
	if (position == std::string::npos)
	{
		std::cout << "'" << s1 << "' was not found in the file '" << filename << "'" << std::endl;
		return (0);
	}
	std::cout << "'" << s1 << "' was successfully replaced by '" << s2 << "' in the file '" << filename << "'" << std::endl;
	std::ofstream outputFile (newFile.c_str(), std::ofstream::out);
	outputFile << buffer;
	outputFile.close();
	return (0);
}
