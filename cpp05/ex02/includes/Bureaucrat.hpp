/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:03:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 09:59:42 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat( std::string const name, int const grade );
		Bureaucrat( Bureaucrat const& src );
		~Bureaucrat( void );

		std::string const&	getName( void ) const;
		int	const&			getGrade( void ) const;

		void	gradeUp( void );
		void	gradeDown( void );
		void	signForm( AForm& form );
		void	executeForm( AForm const & form );

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat&	operator=( Bureaucrat const& rhs );
		
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BLACKI "\e[0;90m"
# define RESET "\033[0m"

#endif
