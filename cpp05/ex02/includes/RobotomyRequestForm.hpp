/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:51:50 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 14:11:48 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( std::string const& target );
		RobotomyRequestForm( RobotomyRequestForm const& src );
		~RobotomyRequestForm( void );

		std::string const&	getTarget( void );
		
		void	execute( Bureaucrat const& executor ) const;

	private:
		const std::string _target;
		
		RobotomyRequestForm( void );
		RobotomyRequestForm& operator=( RobotomyRequestForm const& rhs );
};

#endif
