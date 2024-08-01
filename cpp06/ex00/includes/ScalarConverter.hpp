/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:38:23 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/01 12:37:59 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <climits>
# include <limits>
# include <cerrno>
# include <cstdlib>
# include <iomanip>
# include <cctype>
# include "colors.hpp"

class	ScalarConverter
{
	public:
		static void	convert( std::string const& literal );

		enum	inputType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
		};

		struct Scalar
		{
			inputType	type;
			char		charValue;
			int			intValue;
			float		floatValue;
			double		doubleValue;
			bool		charDisplayable;
			bool		charImpossible;
			bool		intImpossible;
			size_t		floatingPointPrecision;
			
			Scalar(void);
		};
		
		class	InvalidInputException	: std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const& src );
		ScalarConverter& operator=( ScalarConverter const& rhs );
		~ScalarConverter( void );

		inputType	identifyType( std::string const& literal, ScalarConverter::Scalar& scalar ) const;
		bool		isChar( std::string const& literal, ScalarConverter::Scalar& scalar ) const;
		bool		isInt( std::string const& literal, ScalarConverter::Scalar& scalar ) const;
		bool		isFloat( std::string const& literal, ScalarConverter::Scalar& scalar ) const;
		bool		isDouble( std::string const& literal, ScalarConverter::Scalar& scalar ) const;

		void	convertToChar( ScalarConverter::Scalar& scalar )  const;
		void	convertToInt( ScalarConverter::Scalar& scalar )  const;
		void	convertToFloat( ScalarConverter::Scalar& scalar )  const;
		void	convertToDouble( ScalarConverter::Scalar& scalar )  const;
};

std::ostream&	operator<<( std::ostream& os, ScalarConverter::Scalar const& scalar );

# define NANF std::numeric_limits<float>::quiet_NaN()
# define INFF std::numeric_limits<float>::infinity()
# define NAN_DOUBLE std::numeric_limits<double>::quiet_NaN()
# define INF_DOUBLE std::numeric_limits<double>::infinity()
# define FLOAT_MAX std::numeric_limits<float>::max()

#endif
