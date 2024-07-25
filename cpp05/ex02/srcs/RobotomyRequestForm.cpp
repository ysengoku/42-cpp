/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:52:00 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 14:35:45 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("Shrubbery Creation Form", 72, 45)
{
	std::cout << BLACKI << "RobotomyRequestForm: Default constructor called" << RESET << std::endl;
	this->_signed = false;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const& target )
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << BLACKI << "RobotomyRequestForm: Constructor called" << RESET << std::endl;
	this->_signed = false;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const& src )
	: AForm(src), _target(src._target)
{
	std::cout << BLACKI << "RobotomyRequestForm: Copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( RobotomyRequestForm const& rhs)
{
	std::cout << BLACKI << "RobotomyRequestForm: Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
		this->_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << BLACKI << "RobotomyRequestForm: Destructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	RobotomyRequestForm::getTarget( void )
{
	return (this->_target);
}
/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	RobotomyRequestForm::execute( Bureaucrat const& executor ) const
{
	(void)executor;
	// Makes some drilling noises. 
	// Then, informs that <target> has been robotomized successfully 50% of the time.
	// Otherwise, informs that the robotomy failed.
}
