/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:02:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 08:20:30 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	constructorTest( int grade )
{
	std::cout << BLUE << "--- Test with grade " << grade << " ---" << RESET << std::endl;
	Bureaucrat	*test;
	try
	{
		test = new Bureaucrat("Test", grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}	
	std::cout << *test << std::endl;
	std::cout << BLUE << "Copy constructor test" << RESET << std::endl;
	Bureaucrat copy1(*test);
	std::cout << copy1 << std::endl;
	delete test;
}

void	gardeUpDownTest( void )
{
	std::cout << BLUE << "--- Basic test ---" << RESET << std::endl;
	{
		Bureaucrat	*bob;
		try
		{
			bob = new Bureaucrat("Bob", 150);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
			return ;
		}
		std::cout << *bob << std::endl;
		bob->gradeUp();
		std::cout << *bob << std::endl;
		bob->gradeDown();
		std::cout << *bob << std::endl;
		delete bob;
	}
	{
		Bureaucrat	*will;
		try
		{
			will = new Bureaucrat("Will", 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
			return ;
		}
		std::cout << *will << std::endl;
		will->gradeDown();
		std::cout << *will << std::endl;
		will->gradeUp();
		std::cout << *will << std::endl;
		delete will;
	}
	std::cout << BLUE << "--- Exception test ---" << RESET << std::endl;
	{
		Bureaucrat	*joe;
		try
		{
			joe = new Bureaucrat("Joe", 150);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
			return ;
		}
		std::cout << *joe << std::endl;
		joe->gradeDown();
		std::cout << *joe << std::endl;
		delete joe;
	}
	{
		Bureaucrat *sam;
		try
		{
			sam = new Bureaucrat("Sam", 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << *sam << std::endl;
		sam->gradeUp();
		std::cout << *sam << std::endl;
		delete sam;
	}
}

int	main( void )
{
	std::cout << std::endl << CYAN << "====== Constructor test ======" << RESET << std::endl;
	constructorTest(1);
	constructorTest(150);
	constructorTest(0);
	constructorTest(151);
	
	std::cout << std::endl << CYAN << "====== Grade up/down test ======" << RESET << std::endl;
	gardeUpDownTest();
	return (0);
}
