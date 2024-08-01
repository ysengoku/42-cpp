/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:38:27 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/01 12:59:34 by yusengok         ###   ########.fr       */
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
	: charValue(0), intValue(0), floatValue(0.0f), doubleValue(0.0),
	charDisplayable(true), charImpossible(false), intImpossible(false), floatingPointPrecision(1) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void	ScalarConverter::convert( std::string const& literal )
{
	ScalarConverter 		tmp;
	ScalarConverter::Scalar scalar;

	scalar.type = tmp.identifyType(literal, scalar);
	tmp.convertToInt(scalar);
	tmp.convertToChar(scalar);
	tmp.convertToFloat(scalar);
	tmp.convertToDouble(scalar);
	std::cout << scalar << std::endl;
}

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

ScalarConverter::inputType	ScalarConverter::identifyType( std::string const& literal, ScalarConverter::Scalar& scalar ) const
{
	if (ScalarConverter::isChar(literal, scalar))
		return (CHAR);
	if (ScalarConverter::isInt(literal, scalar))
		return (INT);
	if (ScalarConverter::isFloat(literal, scalar))
		return (FLOAT);
	if (ScalarConverter::isDouble(literal, scalar))
		return (DOUBLE);
	throw ScalarConverter::InvalidInputException();
}

bool	ScalarConverter::isChar( std::string const& literal, ScalarConverter::Scalar& scalar ) const
{
	if (literal.length() != 1 || !std::isprint(literal[0]) || std::isdigit(literal[0]))
		return (false);
	scalar.charValue = literal[0];
	return (true);
}

bool	ScalarConverter::isInt( std::string const& literal, ScalarConverter::Scalar& scalar ) const
{
	errno = 0;
	char	*end;
	long	num = std::strtol(literal.c_str(), &end, 10);
	if (*end != '\0')
		return (false);
	if (errno == ERANGE || num > INT_MAX || num < INT_MIN)
		return (false);
	scalar.intValue = static_cast<int>(num);
    return (true);
}

bool	ScalarConverter::isFloat( std::string const& literal, ScalarConverter::Scalar& scalar ) const
{
	if (literal == "nanf")
	{
		scalar.floatValue = NANF;
		return (true);
	}
	if (literal == "+inff" || literal == "inff")
	{
		scalar.floatValue = INFF;
		return (true);
	}
	if (literal == "-inff")
	{
		scalar.floatValue = -INFF;
		return (true);
	}
	if (literal.find('.') == std::string::npos)
		return (false);
	errno = 0;
	char	*end;
	float	num;
	double	tmp = std::strtod(literal.c_str(), &end);
	if (*end != 'f' || *(end + 1) != '\0')
		return (false);
	num = static_cast<float>(tmp);
	if (errno == ERANGE || num > FLOAT_MAX || num < -FLOAT_MAX)
		return (false);
	scalar.floatValue = num;
	scalar.floatingPointPrecision = literal.length() - literal.find('.') - 2;
	return (true);
}
	
bool	ScalarConverter::isDouble( std::string const& literal, ScalarConverter::Scalar& scalar ) const
{
	if (literal == "nan")
	{
		scalar.doubleValue = NAN_DOUBLE;
		return (true);
	}
	if (literal == "+inf" || literal == "inf")
	{
		scalar.doubleValue = INF_DOUBLE;
		return (true);
	}
	if (literal == "-inf")
	{
		scalar.doubleValue = -INF_DOUBLE;
		return (true);
	}
	if (literal.find('.') == std::string::npos)
		return (false);
	errno = 0;
	char	*end;
	double	num = std::strtod(literal.c_str(), &end);
	if (*end != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	scalar.doubleValue = num;
	scalar.floatingPointPrecision = literal.length() - literal.find('.') - 1;
	return (true);
}

void	ScalarConverter::convertToInt( ScalarConverter::Scalar& scalar ) const
{
	switch (scalar.type)
	{
		case INT:
			break ;
		case CHAR:
			scalar.intValue = static_cast<int>(scalar.charValue);
			break ;
		case FLOAT:
			if (scalar.floatValue != scalar.floatValue 
				|| scalar.floatValue == INFF || scalar.floatValue == -INFF
				|| scalar.floatValue < INT_MIN || scalar.floatValue > INT_MAX)
				scalar.intImpossible = true;
			else
				scalar.intValue = static_cast<int>(scalar.floatValue);
			break ;
		case DOUBLE:
			if (scalar.doubleValue != scalar.doubleValue
				|| scalar.doubleValue == INF_DOUBLE || scalar.doubleValue == -INF_DOUBLE
				|| scalar.doubleValue < INT_MIN || scalar.doubleValue > INT_MAX)
				scalar.intImpossible = true;
			else
				scalar.intValue = static_cast<int>(scalar.doubleValue);
			break ;
	}
}

void	ScalarConverter::convertToChar( ScalarConverter::Scalar& scalar ) const
{
	switch (scalar.type)
	{
		case CHAR:
			break;
		case INT:
			if (scalar.intValue < CHAR_MIN || scalar.intValue > CHAR_MAX)
				scalar.charImpossible = true;
			else
			{
				scalar.charValue = static_cast<char>(scalar.intValue);
				scalar.charDisplayable = std::isprint(scalar.charValue);
			}
			break ;
		case FLOAT:
			if (scalar.intValue < CHAR_MIN || scalar.intValue > CHAR_MAX || scalar.intImpossible)
				scalar.charImpossible = true;
			else
			{
				scalar.charValue = static_cast<char>(scalar.floatValue);
				scalar.charDisplayable = std::isprint(scalar.charValue);
			}
			break ;
		case DOUBLE:
			if (scalar.intValue < CHAR_MIN || scalar.intValue > CHAR_MAX || scalar.intImpossible)
				scalar.charImpossible = true;
			else
			{
				scalar.charValue = static_cast<char>(scalar.doubleValue);
				scalar.charDisplayable = std::isprint(scalar.charValue);
			}
			break ;
	}
}

void	ScalarConverter::convertToFloat( ScalarConverter::Scalar& scalar ) const
{
	switch (scalar.type)
	{
		case FLOAT:
			break ;
		case CHAR:
			scalar.floatValue = static_cast<float>(scalar.charValue);
			break ;
		case INT:
			scalar.floatValue = static_cast<float>(scalar.intValue);
			break ;
		case DOUBLE:
			scalar.floatValue = static_cast<float>(scalar.doubleValue);
			break ;
	}
}

void	ScalarConverter::convertToDouble( ScalarConverter::Scalar& scalar ) const
{
	switch (scalar.type)
	{
		case DOUBLE:
			break ;
		case CHAR:
			scalar.doubleValue = static_cast<double>(scalar.charValue);
			break ;
		case INT:
			scalar.doubleValue = static_cast<double>(scalar.intValue);
			break ;
		case FLOAT:
			scalar.doubleValue = static_cast<double>(scalar.floatValue);
			break ;
	}
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

std::ostream&	operator<<( std::ostream& os, ScalarConverter::Scalar const& scalar )
{
	if (!scalar.charDisplayable)
		os << "char:   Not displayable" << std::endl;
	else if (scalar.charImpossible)
		os << "char:   impossible" << std::endl;
	else
		os << "char:   '" << scalar.charValue << '\'' << std::endl;	
	if (scalar.intImpossible)
		os << "int:    impossible" << std::endl;
	else
		os << "int:    " << scalar.intValue << std::endl;
	os << "float:  " << std::fixed << std::setprecision(scalar.floatingPointPrecision) << scalar.floatValue << 'f' <<std::endl;
	os << "double: " << std::fixed << std::setprecision(scalar.floatingPointPrecision) << scalar.doubleValue;
	return (os);
}

/*============================================================================*/
/*       Exception                                                            */
/*============================================================================*/

const char*	ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid input value.");
}
