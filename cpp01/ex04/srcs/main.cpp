/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:39:06 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/28 10:04:19 by yusengok         ###   ########.fr       */
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
	Replacer replacer(filename, s1, s2);
	if (replacer.replaceText() == 1)
		return (1);
	return (0);
}

// test1 ---> s1: world, s2: universe
// test2 ---> s1: fox, s2: cat
// test3 ---> s1: be, s2: exist

// int	main( int argc, char **argv )
// {
// 	std::string line;
// 	size_t		position;
// 	char		nextChar;
// 	bool		replaced = false;
	
// 	if (argc != 4)
// 	{
// 		std::cerr << "Usage: ./Replace filename s1 s2" << std::endl;
// 		return (1);
// 	}
// 	std::string	const filename = argv[1];
// 	std::string const s1 = argv[2];
// 	std::string const s2 = argv[3];
// 	std::string const replacedFile = filename + ".replace";
// 	std::ifstream inputFile(filename.c_str(), std::ifstream::in);
// 	if (!inputFile.is_open())
// 	{
//     	std::cerr << "Failed to open the file: " << filename << std::endl;
//     	return (1);
// 	}
// 	std::ofstream outputFile (replacedFile.c_str(), std::ofstream::out | std::ofstream::trunc);
// 	if (!outputFile.is_open())
// 	{
//     	std::cerr << "Failed to open the output file: " << replacedFile << std::endl;
// 		inputFile.close();
//     	return (1);
// 	}
// 	outputFile.close();
// 	outputFile.open(replacedFile.c_str(), std::ofstream::app);
// 	if (!outputFile.is_open())
// 	{
//     	std::cerr << "Failed to open the output file: " << replacedFile << std::endl;
// 		inputFile.close();
//     	return (1);
// 	}
// 	while (std::getline(inputFile, line))
// 	{
// 		position = line.find(s1);
// 		while (position != std::string::npos)
// 		{
// 			if (position + s1.length() < line.length())
// 			{
// 				nextChar = line[position + s1.length()];
// 				if (!std::isalnum(nextChar))
// 				{
// 					line.erase(position, s1.length());
// 					line.insert(position, s2);
// 					replaced = true;
// 				}
// 				position = line.find(s1, position + 1);
// 			}
// 		}
// 		outputFile << line + '\n';
// 	}
// 	inputFile.close();
// 	outputFile.close();
// 	if (replaced)
// 		std::cout << "'" << s1 << "' was successfully replaced by '" << s2 << "' in the file '" << replacedFile << "'" << std::endl;
// 	else
// 		std::cout << "'" << s1 << "' was not found in the file '" << filename << "'" << std::endl;
// 	return (0);
// }
