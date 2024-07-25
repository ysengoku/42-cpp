/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:02:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 14:37:37 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	shrubberyCreationFormTest( std::string target, int grade )
{
	std::cout << CYAN << "====== Shrubbery Creation Form =====" << RESET << std::endl;
	{
		std::cout << BLUE << "Copy constructor test" << RESET << std::endl;
		ShrubberyCreationForm	original("target");
		ShrubberyCreationForm	copy1(original);
		std::cout << copy1 << std::endl;
		std::cout << BLUE << "Copy assignment operator test" << RESET << std::endl;
		ShrubberyCreationForm copy2;
		copy2 = original;
		std::cout << copy2 << std::endl;
	}
	{
		std::cout << BLUE << "Execute test" << RESET << std::endl;
		/* Create forms */
		AForm		*shrubberyCreationForm;
		shrubberyCreationForm = new ShrubberyCreationForm(target);
		std::cout << *shrubberyCreationForm << std::endl;
		
		/* Create bureaucrat */
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
		
		/* Sign */
		try
		{
			bureaucrat->signForm(*shrubberyCreationForm);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << *shrubberyCreationForm << std::endl;

		/* Execute */
		bureaucrat->executeForm(*shrubberyCreationForm);
		
		delete shrubberyCreationForm;
		delete bureaucrat;
	}
}

int	main( void )
{
	shrubberyCreationFormTest("entrance", 50);

	return (0);
}
