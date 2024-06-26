/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:51 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 15:55:12 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "\033[36m===== Address =====\033[0m" << std::endl;
	std::cout << "Memory address of the string variable: ";
	std::cout << "\033[32m" << &string << "\033[0m" << std::endl;
	std::cout << "Memory address held by stringPTR: ";
	std::cout << "\033[32m" << stringPTR << "\033[0m" << std::endl;
	std::cout << "Memory address held by stringREF: ";
	std::cout << "\033[32m" << &stringREF << "\033[0m" << std::endl;
	std::cout << "\033[36m===== Value =====\033[0m" << std::endl;
	std::cout << "Value of the string variable: ";
	std::cout << "\033[32m" << string << "\033[0m" << std::endl;
	std::cout << "Value pointed to by stringPTR: ";
	std::cout << "\033[32m" << *stringPTR << "\033[0m" << std::endl;
	std::cout << "Value pointed to by stringREF: ";
	std::cout << "\033[32m" << stringREF << "\033[0m" << std::endl;
	return (0);
}
