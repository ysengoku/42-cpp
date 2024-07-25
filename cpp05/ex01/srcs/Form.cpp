/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:29:58 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 10:37:45 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Form::Form( void )
	: _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << BLACKI << "Form: Default constructor called." << RESET << std::endl;
}

Form::Form( std::string name, int gradeToSign, int gradeToExecute )
	: _name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << BLACKI << "Form: Constructor called." << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form( Form const& src )
	: _name(src._name),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << BLACKI << "Form: Copy constructor called." << RESET << std::endl;
}

Form&	Form::operator=( Form const& rhs )
{
	std::cout << BLACKI << "Form: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->~Form();
		new (this) Form(rhs._name, rhs._gradeToSign, rhs._gradeToExecute);
		this->_signed = rhs._signed;
	}
	return (*this);
}

Form::~Form( void )
{
	std::cout << BLACKI << "Form: Detructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

std::ostream&	operator<<( std::ostream& os, Form const& form )
{
	os << "---------------------------------" << std::endl \
	<< " Form Name: " << form.getName() << std::endl \
	<< " Signature status: " << form.getSignatureStatus() << std::endl \
	<< " Grade required to sign: " << form.getGradeToSign() << std::endl \
	<< " Grade required to execute: " << form.getGradeToExecute() << std::endl \
	<< "---------------------------------";
	return (os);
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	Form::getName( void ) const
{
	return (this->_name);
}

int const&	Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int const&	Form::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

bool	Form::getSignatureStatus( void ) const
{
	return (this->_signed);
}

void	Form::setSignatureStatus(bool status)
{
	if (this->_signed != status)
		this->_signed = status;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Form::beSigned( Bureaucrat const& bureaucrat )
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

/*============================================================================*/
/*       Exception classes                                                    */
/*============================================================================*/

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("The grade is not high enough.");
}
