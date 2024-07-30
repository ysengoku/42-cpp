/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:38:27 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 13:39:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( ScalarConverter const& src ) { (void)src; }

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const& rhs )
{
	(void)rhs;
	return (*this);
}

ScalarConverter::Scalar::Scalar( void )
	: charValue(0), intValue(0), floatValue(0.0f), doubleValue(0.0) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	ScalarConverter::convert( std::string const& literal )
{
	Scalar scalar;
	ScalarConverter tmp;

	scalar.type = tmp.identifyType(literal);
	scalar.charValue = tmp.convertToChar(literal);
	scalar.intValue = tmp.convertToInt(literal);
	scalar.floatValue = tmp.convertToFloat(literal);
	scalar.doubleValue = tmp.convertToDouble(literal);
	// handle overflow etc
	std::cout << scalar << std::endl;
}

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

ScalarConverter::inputType	ScalarConverter::identifyType( std::string const& literal ) const
{
	if (ScalarConverter::isChar(literal))
		return (CHAR);
	if (ScalarConverter::isInt(literal))
		return (INT);
	if (ScalarConverter::isFloat(literal))
		return (FLOAT);
	if (ScalarConverter::isDouble(literal))
		return (DOUBLE);
	throw ScalarConverter::InvalidInputException();
}

bool	ScalarConverter::isChar( std::string const& literal ) const
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt( std::string const& literal ) const
{

}

bool	ScalarConverter::isFloat( std::string const& literal ) const
{

}

bool	ScalarConverter::isDouble( std::string const& literal ) const
{

}

char	ScalarConverter::convertToChar( std::string const& literal ) const
{

}

int		ScalarConverter::convertToInt( std::string const& literal ) const
{

}

float	ScalarConverter::convertToFloat( std::string const& literal ) const
{

}

double	ScalarConverter::convertToDouble( std::string const& literal ) const
{

}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

std::ostream&	operator<<( std::ostream& os, ScalarConverter::Scalar const& scalar )
{
	os << "char:   " << scalar.charValue << std::endl \
	<< "int:    " << scalar.intValue << std::endl \
	<< "float:  " << scalar.floatValue << std::endl \
	<< "double: " << scalar.doubleValue << std::endl;
}

/*============================================================================*/
/*       Exception                                                            */
/*============================================================================*/

const char*	ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid input value.\n");
}
