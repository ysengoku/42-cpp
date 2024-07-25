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
		std::cout << "Copy constructor test" << RESET << std::endl;
		ShrubberyCreationForm	original("target");
		ShrubberyCreationForm	copy1(original);
		std::cout << copy1 << std::endl;
		std::cout << BLUE << "Copy assignment operator test" << RESET << std::endl;
		ShrubberyCreationForm copy2;
		copy2 = original;
		std::cout << copy2 << std::endl;
	}
	{
		std::cout << BLUE << "+++ Presidential Pardon Form +++" << std::endl;
		std::cout << "Copy constructor test" << RESET << std::endl;
		// AForm	*original;
		// original = new PresidentialPardonForm("target");
		// PresidentialPardonForm	copy1(*original);
		PresidentialPardonForm	original("target");
		PresidentialPardonForm	copy1(original);
		std::cout << copy1 << std::endl;
		std::cout << BLUE << "Copy assignment operator test" << RESET << std::endl;
		PresidentialPardonForm copy2;
		copy2 = original;
		std::cout << copy2 << std::endl;
	}
}

void	shrubberyCreationFormTest( std::string target, int grade )
{
	std::cout << std::endl << CYAN << "====== Shrubbery Creation Form =====" << RESET << std::endl;
	AForm		*shrubberyCreationForm;
	shrubberyCreationForm = new ShrubberyCreationForm(target);
	std::cout << *shrubberyCreationForm << std::endl;
	Bureaucrat	*bureaucrat;
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
	try
	{
		bureaucrat->signForm(*shrubberyCreationForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << *shrubberyCreationForm << std::endl;
	bureaucrat->executeForm(*shrubberyCreationForm);
	delete shrubberyCreationForm;
	delete bureaucrat;
}

int	main( void )
{
	constructorsTests();
	shrubberyCreationFormTest("entrance", 50);
	shrubberyCreationFormTest("garden", 140);
	shrubberyCreationFormTest("garden", 148);

	return (0);
}
