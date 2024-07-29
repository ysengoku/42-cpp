/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:30:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 11:48:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Intern::Intern( void )
{
	std::cout << BLACKI << "Intern: Default constructor called" << RESET << std::endl;
}

Intern::Intern( Intern const& src )
{
	std::cout << BLACKI << "Intern: Copy constructor called" << RESET << std::endl;
	*this = src;
}

Intern& Intern::operator=( Intern const& rhs )
{
	std::cout << BLACKI << "Intern: Copy assignment operator called" << RESET << std::endl;
	(void)rhs;
	return (*this);
}

Intern::~Intern( void )
{
	std::cout << BLACKI << "Intern: Destructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

std::string	parseFormName(std::string const& name)
{
	std::string	formNameInLower;
	std::string	suffix = " form";
	if (name.empty())
		throw AForm::InvalidNameException();
	for (size_t i = 0; i < name.length(); i++)
		formNameInLower += tolower(name[i]);
	if (name.length() > 5 && formNameInLower.substr(formNameInLower.length() - suffix.length()) == suffix)
		formNameInLower = formNameInLower.substr(0, formNameInLower.length() - suffix.length());
	return (formNameInLower);
}

AForm*	Intern::makeForm( std::string const& formName, std::string const& target )
{
	std::string	formNameInLower = parseFormName(formName);
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	size_t	i;
	for (i = 0; i < 3; i++)
	{
		if (formNameInLower == names[i])
		{
			std::cout << "Intern creates " << formName << "." << std::endl;
			break ;
		}
	}
	switch(i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			throw AForm::InvalidNameException();
	}
}
