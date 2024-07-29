/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:52:00 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 10:06:34 by yusengok         ###   ########.fr       */
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
		this->_signed = rhs._signed;
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
	if (!this->_signed)
		throw RobotomyRequestForm::NotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw RobotomyRequestForm::GradeTooLowException();
	else
	{
		std::cout << "VRRRRRRRRRR" << std::endl;
		int randomNum = std::rand();
		if (randomNum % 2 == 0)
			std::cout << this->_target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomy failed." << std::endl;
	}
}
