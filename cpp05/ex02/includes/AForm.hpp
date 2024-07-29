/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:30:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 09:31:54 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAFORM_HPP
# define AAFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm( void );
		AForm( std::string name, int gradeToSign, int gradeToExecute);
		AForm( AForm const& src );
		virtual	~AForm( void );

		std::string const&	getName( void ) const;
		bool				getSignatureStatus( void ) const;
		int const& 			getGradeToSign( void ) const;
		int	const&			getGradeToExecute( void ) const;
		void				setSignatureStatus(bool status);
		
		void				beSigned( Bureaucrat const& bureaucrat );
		virtual void		execute( Bureaucrat const & executor ) const = 0;

		class	GradeTooHighException : public std::exception
		{
			virtual const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			virtual const char*	what() const throw();
		};
	
		class	NotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};

	protected:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	private:
		AForm& operator=( AForm const& rhs );
};

std::ostream&	operator<<(std::ostream& os, AForm const& Aform);

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BLACKI "\e[0;90m"
# define RESET "\033[0m"

#endif
