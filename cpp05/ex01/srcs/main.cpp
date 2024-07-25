/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:02:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 10:35:17 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	constructorTest( int gradeToSign, int gradeToExecute )
{
	std::cout << BLUE << "--- Test with grade required to sign " << gradeToSign \
	<< " / to execute " << gradeToExecute << " ---" << RESET << std::endl;
	Form	*test;
	try
	{
		test = new Form("Test", gradeToSign, gradeToExecute);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}	
	std::cout << *test << std::endl;
	std::cout << BLUE << "Copy constructor test" << RESET << std::endl;
	Form copy1(*test);
	std::cout << copy1 << std::endl;
	std::cout << BLUE << "Copy assignment operator test" << RESET << std::endl;
	Form copy2;
	copy2 = *test;
	std::cout << copy2 << std::endl;
	delete test;
}

void	signTest1( int gradeToSign, int grade )
{
	Form		*form;
	Bureaucrat	*bureaucrat;

	/* Create forms */
	try
	{
		form = new Form("Purchase agreement", gradeToSign, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}	
	std::cout << *form << std::endl;

	/* Create bureaucrat */
	try
	{
		bureaucrat = new Bureaucrat("Bob", grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << *bureaucrat << std::endl;

	/* Sign tests */
	try
	{
		bureaucrat->signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << *form << std::endl;
	bureaucrat->gradeDown();
	form->setSignatureStatus(false);
	std::cout << *form << std::endl;
	try
	{
		bureaucrat->signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << *form << std::endl << std::endl;
	delete form;
	delete bureaucrat;
}

void	signTest2( int gradeToSign, int grade )
{
	Form		*form;
	Bureaucrat	*bureaucrat;

	/* Create forms */
	try
	{
		form = new Form("Expenses report", gradeToSign, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}	
	std::cout << *form << std::endl;

	/* Create bureaucrat */
	try
	{
		bureaucrat = new Bureaucrat("Joe", grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << *bureaucrat << std::endl;

	/* Sign tests */
	try
	{
		bureaucrat->signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << *form << std::endl;
	bureaucrat->gradeUp();
	form->setSignatureStatus(false);
	std::cout << *form << std::endl;
	try
	{
		bureaucrat->signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << *form << std::endl << std::endl;
	delete form;
	delete bureaucrat;
}

int	main( void )
{
	std::cout << std::endl << CYAN << "====== Constructor test ======" << RESET << std::endl;
	constructorTest(1, 2);
	constructorTest(149, 150);
	constructorTest(1, 0);
	constructorTest(151, 150);
	
	std::cout << std::endl << CYAN << "====== Sign tests ======" << RESET << std::endl;
	signTest1(5, 3);
	signTest1(5, 5);
	signTest1(1, 5);

	signTest2(10, 8);
	signTest2(10, 11);
	signTest2(12, 15);
	return (0);
}
