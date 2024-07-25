/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:02:56 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 11:50:35 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "AForm.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Bureaucrat::Bureaucrat( void )
{
	std::cout << BLACKI << "Bureaucrat: Default constructor called." << RESET << std::endl; 	
}

Bureaucrat::Bureaucrat( std::string const name, int const grade )
	: _name(name), _grade(grade)
{
	std::cout << BLACKI << "Bureaucrat: Constructor called." << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const& src )
	: _name(src._name), _grade(src._grade)
{
	std::cout << BLACKI << "Bureaucrat: Copy constructor called." << RESET << std::endl;
}

Bureaucrat&	Bureaucrat::operator=( Bureaucrat const& rhs )
{
	std::cout << BLACKI << "Bureaucrat: Copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->~Bureaucrat();
		new (this) Bureaucrat(rhs._name, rhs._grade);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << BLACKI << "Bureaucrat: Destructor called." << RESET << std::endl; 
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int const&	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	Bureaucrat::gradeUp( void )
{
	try
	{
		--this->_grade;
		if (this->_grade < 1)
		{
			++this->_grade;
			throw Bureaucrat::GradeTooHighException();
		}
		else
			std::cout << YELLOW << this->getName() << " has moved up to grade " << this->getGrade() << "." << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::gradeDown( void )
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
		{
			++this->_grade;
			std::cout << YELLOW << this->getName() << " has moved down to grade " << this->getGrade() << "." << RESET << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::signForm( AForm& form )
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << this->_name << " couldn't sign " << form.getName() << ". " \
		<< e.what() << RESET << std::endl;
		return ;
	}
	std::cout << this->_name << " signed " << form.getName() << " 🖊️" << std::endl;
}

void	Bureaucrat::executeForm( AForm const& form )
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception&e)
	{
		std::cout << RED << this->_name << " couldn't execute " << form.getName() << ". " \
		<< e.what() << RESET << std::endl;
		return ;
	}
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}

/*============================================================================*/
/*       Exception classes                                                    */
/*============================================================================*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade cannot be higher than 1.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade cannot be lower than 150.");
}
