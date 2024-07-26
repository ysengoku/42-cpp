/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:02:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 14:58:07 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ctime>
#include "../includes/Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	constructorsTests( void )
{
	std::cout << std::endl << CYAN << "====== Constructors tests =====" << RESET << std::endl;
	{
		std::cout << BLUE << "+++ Shrubbery Creation Form +++" << std::endl;
		AForm	*original;
		original = new ShrubberyCreationForm("TEST");
		std::cout << *original << std::endl << "▶︎ Target: " << dynamic_cast<ShrubberyCreationForm*>(original)->getTarget() << std::endl;

		std::cout << BLUE << "Copy constructor test" << RESET << std::endl;
		ShrubberyCreationForm	copy1(*dynamic_cast<ShrubberyCreationForm*>(original));
		std::cout << copy1 << std::endl << "▶︎ Target: " << copy1.getTarget() << std::endl;

		std::cout << BLUE << "Copy assignment operator test" << RESET << std::endl;
		ShrubberyCreationForm copy2;
		copy2 = *dynamic_cast<ShrubberyCreationForm*>(original);
		std::cout << copy2 << std::endl << "▶︎ Target: " << copy2.getTarget() << std::endl;
		delete original;
	}
	{
		std::cout << std::endl << BLUE << "+++ Robotomy Request Form +++" << std::endl;
		AForm	*original;
		original = new RobotomyRequestForm("TEST");
		std::cout << *original << std::endl << "▶︎ Target: " << dynamic_cast<RobotomyRequestForm*>(original)->getTarget() << std::endl; ;
		std::cout << BLUE << "Copy constructor test" << RESET << std::endl; 
		RobotomyRequestForm	copy1(*dynamic_cast<RobotomyRequestForm*>(original));
		std::cout << copy1 << std::endl << "▶︎ Target: " << copy1.getTarget() << std::endl;
		std::cout << BLUE << "Copy assignment operator test" << RESET << std::endl;
		RobotomyRequestForm copy2;
		copy2 = *dynamic_cast<RobotomyRequestForm*>(original);
		std::cout << copy2 << std::endl << "▶︎ Target: " << copy2.getTarget() << std::endl;
		delete original;
	}
	{
		std::cout << std::endl << BLUE << "+++ Presidential Pardon Form +++" << std::endl;
		AForm	*original;
		original = new PresidentialPardonForm("TEST");
		std::cout << *original << std::endl << "▶︎ Target: " << dynamic_cast<PresidentialPardonForm*>(original)->getTarget() << std::endl; ;
		std::cout << BLUE << "Copy constructor test" << RESET << std::endl;
		PresidentialPardonForm	copy1(*dynamic_cast<PresidentialPardonForm*>(original));
		std::cout << copy1 << std::endl << "▶︎ Target: " << copy1.getTarget() << std::endl;
		std::cout << BLUE << "Copy assignment operator test" << RESET << std::endl;
		PresidentialPardonForm copy2;
		copy2 = *dynamic_cast<PresidentialPardonForm*>(original);
		std::cout << copy2 << std::endl << "▶︎ Target: " << copy2.getTarget() << std::endl;
		delete original;
	}
}

void	shrubberyCreationFormTest( std::string target, int grade )
{
	std::cout << std::endl << CYAN << "====== Shrubbery Creation Form =====" << RESET << std::endl;
	AForm		*form;
	Bureaucrat	*bureaucrat;
	form = new ShrubberyCreationForm(target);
	std::cout << YELLOW << *form << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Bob", grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << *bureaucrat << RESET << std::endl;
	try
	{
		bureaucrat->signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW << *form << RESET << std::endl;
	bureaucrat->executeForm(*form);
	delete form;
	delete bureaucrat;
}

void	robotomyRequestFormTest( std::string const& target, int grade )
{
	std::cout << std::endl << CYAN << "====== Robotomy Request Form =====" << RESET << std::endl;
	AForm		*form;
	Bureaucrat	*bureaucrat;
	form = new RobotomyRequestForm(target);
	std::cout << YELLOW << *form << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Joe", grade);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << *bureaucrat << RESET << std::endl;
	try
	{
		bureaucrat->signForm(*form);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW << *form << RESET << std::endl;
	bureaucrat->executeForm(*form);
	delete form;
	delete bureaucrat;
}

void	presidentialPardonFormTest( std::string const& target, int grade )
{
	std::cout << std::endl << CYAN << "====== Presidential Pardon Form =====" << RESET << std::endl;
	AForm		*form;
	Bureaucrat	*bureaucrat;
	form = new PresidentialPardonForm(target);
	std::cout << YELLOW << *form << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Sam", grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << *bureaucrat << RESET << std::endl;
	try
	{
		bureaucrat->signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl;
	}
	std::cout << YELLOW << *form << RESET << std::endl;
	bureaucrat->executeForm(*form);
	delete form;
	delete bureaucrat;
}


int	main( void )
{
	constructorsTests();

	shrubberyCreationFormTest("entrance", 50);
	shrubberyCreationFormTest("garden", 140);
	shrubberyCreationFormTest("garden", 148);

    std::srand(std::time(0));
	for (int i = 0; i < 5; i++)
		robotomyRequestFormTest("Cyborg", 42);
	robotomyRequestFormTest("Cyborg", 72);
	robotomyRequestFormTest("Cyborg", 100);

	presidentialPardonFormTest("Marvin", 2);
	presidentialPardonFormTest("Marvin", 10);
	presidentialPardonFormTest("Marvin", 100);
	return (0);
}
