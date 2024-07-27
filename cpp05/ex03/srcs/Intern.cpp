/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:30:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 09:31:54 by yusengok         ###   ########.fr       */
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
	(void)rhs;
	std::cout << BLACKI << "Intern: Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Intern::~Intern( void )
{
	std::cout << BLACKI << "Intern: Destructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

AForm*	Intern::makeForm( std::string const& formName, std::string const& target )
{
	std::string	formNameInLower;
	std::string	suffix = " form";
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	if (formName.empty())
		throw AForm::InvalidNameException();
	for (unsigned int i = 0; i < formName.length(); i++)
		formNameInLower += tolower(formName[i]);
	if (formNameInLower.substr(formNameInLower.length() - suffix.length()) == suffix)
		formNameInLower = formNameInLower.substr(0, formNameInLower.length() - suffix.length());
	int	i;
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
