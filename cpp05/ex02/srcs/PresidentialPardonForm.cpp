/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:51:56 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 14:45:34 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm("Shrubbery Creation Form", 25, 5)
{
	std::cout << BLACKI << "PresidentialPardonForm: Default constructor called" << RESET << std::endl;
	this->_signed = false;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const& target )
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << BLACKI << "PresidentialPardonForm: Constructor called" << RESET << std::endl;
	this->_signed = false;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const& src )
	: AForm(src), _target(src._target)
{
	std::cout << BLACKI << "PresidentialPardonForm: Copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( PresidentialPardonForm const& rhs)
{
	std::cout << BLACKI << "PresidentialPardonForm: Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
		this->_target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << BLACKI << "PresidentialPardonForm: Destructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	PresidentialPardonForm::getTarget( void )
{
	return (this->_target);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	PresidentialPardonForm::execute( Bureaucrat const& executor ) const
{
	if (!this->_signed)
		throw NotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
