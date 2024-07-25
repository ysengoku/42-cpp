/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:51:56 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 14:35:52 by yusengok         ###   ########.fr       */
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
	: AForm(src)
{
	std::cout << BLACKI << "PresidentialPardonForm: Copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( PresidentialPardonForm const& rhs)
{
	std::cout << BLACKI << "PresidentialPardonForm: Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(rhs);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << BLACKI << "PresidentialPardonForm: Destructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	PresidentialPardonForm::execute( Bureaucrat const& executor ) const
{
	(void)executor;
	// Informs that <target> has been pardoned by Zaphod Beeblebrox.
}