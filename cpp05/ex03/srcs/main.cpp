/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:02:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 10:47:46 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	formTest( std::string formName, std::string target, int bureaucratGrade, Intern& intern )
{
	std::cout << std::endl << CYAN << "====== " << formName << " =====" << RESET << std::endl;
	AForm		*form;
	Bureaucrat	*bureaucrat;

	try
	{
		bureaucrat = new Bureaucrat("Bob", bureaucratGrade);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << *bureaucrat << RESET << std::endl;
	try
	{
		form = intern.makeForm(formName, target);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		delete bureaucrat;
		return ;
	}
	std::cout << YELLOW << *form << RESET << std::endl;
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

int	main( void )
{
	Intern intern;

	formTest("Shrubbery Creation", "Garden", 100, intern);
	formTest("Shrubbery creation Form", "Garden", 100, intern);

	formTest("Robotomy Request", "Cyborg", 42, intern);
	formTest("ROBOTOMY REQUEST FORM", "Cyborg", 42, intern);

	formTest("Presidential Pardon", "Marvin", 2, intern);
	formTest("presidential pardon", "Marvin", 2, intern);
	formTest("presidential pardon form", "Marvin", 2, intern);

	formTest("invalide form name", "Target", 100, intern);
	formTest("", "Target", 100, intern);
	return (0);
}
