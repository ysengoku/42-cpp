/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:30:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/24 15:20:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form( void );
		Form( std::string name, int gradeToSign, int gradeToExecute);
		Form( Form const& src );
		Form& operator=( Form const& rhs );
		~Form( void );

		std::string const&	getName( void ) const;
		bool				getSignatureStatus( void ) const;
		int const& 			getGradeToSign( void ) const;
		int	const&			getGradeToExecute( void ) const;
		
		void				beSigned( Bureaucrat const& bureaucrat );

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	class	GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	
};

std::ostream&	operator<<(std::ostream& os, Form const& form);

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BLACKI "\e[0;90m"
# define RESET "\033[0m"

#endif