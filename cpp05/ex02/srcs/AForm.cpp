/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:29:58 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 09:32:14 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

AForm::AForm( void )
	: _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << BLACKI << "AForm: Default constructor called." << RESET << std::endl;
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute )
	: _name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << BLACKI << "AForm: Constructor called." << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const& src )
	: _name(src._name),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << BLACKI << "AForm: Copy constructor called." << RESET << std::endl;
}

AForm&	AForm::operator=( AForm const& rhs )
{
	std::cout << BLACKI << "AForm: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

AForm::~AForm( void )
{
	std::cout << BLACKI << "AForm: Detructor called." << RESET << std::endl;
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

std::ostream&	operator<<( std::ostream& os, AForm const& form )
{
	os << "--------------------------------------" << std::endl \
	<< " Form Name: " << form.getName() << std::endl \
	<< " Signature status: " << form.getSignatureStatus() << std::endl \
	<< " Grade required to sign: " << form.getGradeToSign() << std::endl \
	<< " Grade required to execute: " << form.getGradeToExecute() << std::endl \
	<< "--------------------------------------";
	return (os);
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	AForm::getName( void ) const
{
	return (this->_name);
}

int const&	AForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int const&	AForm::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

bool	AForm::getSignatureStatus( void ) const
{
	return (this->_signed);
}

void	AForm::setSignatureStatus(bool status)
{
	if (this->_signed != status)
		this->_signed = status;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	AForm::beSigned( Bureaucrat const& bureaucrat )
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

/*============================================================================*/
/*       Exception classes                                                    */
/*============================================================================*/

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high.");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is not high enough.");
}

const char*	AForm::NotSignedException::what() const throw()
{
	return ("The form is not signed yet.");
}
