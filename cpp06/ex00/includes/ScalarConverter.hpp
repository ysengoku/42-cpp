/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:38:23 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/31 09:51:58 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <climits>
# include <cerrno>
# include <cstdlib>
# include <iomanip>

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

		char	convertToChar( std::string const& literal )  const;
		int		convertToInt( std::string const& literal )  const;
		float	convertToFloat( std::string const& literal )  const;
		double	convertToDouble( std::string const& literal )  const;
};

std::ostream&	operator<<( std::ostream& os, ScalarConverter::Scalar const& scalar );

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GREY "\e[0;90m"
# define RESET "\033[0m"

#endif
