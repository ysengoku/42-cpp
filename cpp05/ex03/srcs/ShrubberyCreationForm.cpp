/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:52:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 10:18:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: AForm("Shrubbery Creation Form", 145, 137)
{
	std::cout << BLACKI << "ShrubberyCreationForm: Default constructor called" << RESET << std::endl;
	this->_signed = false;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const& target )
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << BLACKI << "ShrubberyCreationForm: Constructor called" << RESET << std::endl;
	this->_signed = false;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& src )
	: AForm(src), _target(src._target)
{
	std::cout << BLACKI << "ShrubberyCreationForm: Copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const& rhs)
{
	std::cout << BLACKI << "ShrubberyCreationForm: Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << BLACKI << "ShrubberyCreationForm: Destructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const&	ShrubberyCreationForm::getTarget( void )
{
	return (this->_target);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	ShrubberyCreationForm::execute( Bureaucrat const& executor ) const
{
	if (!this->_signed)
		throw NotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	else
	{
		std::ofstream ofs;
		ofs.open((this->_target + "_shrubbery").c_str(), std::ios::trunc);
		ofs << TREE;
		ofs.close();
	}
}
