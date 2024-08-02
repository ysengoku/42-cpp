/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:28:35 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/02 08:37:47 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "colors.hpp"

Base*	generate(void)
{
	int			randomNum;
	
	std::srand(std::time(0));
	randomNum = std::rand() % 3;
	switch (randomNum)
	{
		case 0:
			std::cout << "A has been generated." << std::endl;
			return (new A());
		case 1:
			std::cout << "B has been generated." << std::endl;
			return (new B());
		case 2:
			std::cout << "C has been generated." << std::endl;
			return (new C());
	}
	return (0);
} 

void	identify(Base* p)
{
	if (p != NULL)
	{
		if (dynamic_cast<A*>(p) != NULL)
		{
			std::cout << "The type is A." << std::endl;
			return ;
		}
		if (dynamic_cast<B*>(p) != NULL)
		{
			std::cout << "The type is B." << std::endl;
			return ;
		}
			if (dynamic_cast<C*>(p) != NULL)
		{
			std::cout << "The type is C." << std::endl;
			return ;
		}
		std::cout << RED << "Unknown type" << RESET << std::endl;
	}
	std::cout << RED << "Error: Received pointer is null." << RESET << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A tmp = dynamic_cast<A&>(p);
		std::cout << "The type is A." << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		B tmp = dynamic_cast<B&>(p);
		std::cout << "The type is B." << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		C tmp = dynamic_cast<C&>(p);
		std::cout << "The type is C." << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << RED << "Unknown type" << RESET << std::endl;
}

int	main( void )
{
	Base	*object;

	object = generate();
	identify(object);
	identify(*object);
	delete object;
	return (0);
}
