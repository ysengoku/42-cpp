/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:30:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/25 09:31:54 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "../includes/Bureaucrat.hpp"
# include "../includes/AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern( void );
		Intern( Intern const& src );
		Intern& operator=( Intern const& rhs );
		~Intern( void );

		AForm*	makeForm( std::string const& formName, std::string const& target );
};

#endif
