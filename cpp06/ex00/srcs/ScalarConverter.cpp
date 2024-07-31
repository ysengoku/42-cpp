/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:38:27 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/31 11:55:22 by yusengok         ###   ########.fr       */
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

	scalar.type = tmp.identifyType(literal, scalar);
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
	if (literal[literal.length() - 1] != 'f')
		return (false);
	errno = 0;
	char	*end;
	float	num;
	double	tmp = std::strtod(literal.c_str(), &end);
	if (*end == '\0' || (*(end + 1) != '\0' && *end != 'f')) // Need to fix the condition
		return (false);
	const float	max_float = std::numeric_limits<float>::max();
    const float	min_positive_float = std::numeric_limits<float>::min();
    const float	lowest_float = std::numeric_limits<float>::lowest();
    const float	neg_max_float = -std::numeric_limits<float>::max();
	num = static_cast<float>(tmp); // Convert before check or after ?
	if (errno == ERANGE || num > max_float) // Add more conditions
		return (false);
	scalar.floatValue = num;
	return (true);
}

bool	ScalarConverter::isDouble( std::string const& literal, ScalarConverter::Scalar& scalar ) const
{
	errno = 0;
	char	*end;
	double	num = std::strtod(literal.c_str(), &end);
	if (errno == ERANGE)
		return (false);
	if (*end != '\0')
		return (false);
	scalar.doubleValue = num;
	return (true);
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

// print decimal floating number
	// std::size_t precision = value.length() - value.find('.') - 1;
    // if (input.length() == precision)
    //     precision = 1;
	// std::cout << std::fixed << std::setprecision(precision) << num << std::endl;

/*============================================================================*/
/*       Exception                                                            */
/*============================================================================*/

const char*	ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid input value.\n");
}
