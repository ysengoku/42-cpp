/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:51:47 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 14:11:41 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm( std::string const& target );
		PresidentialPardonForm( PresidentialPardonForm const& src );
		~PresidentialPardonForm( void );
		
		std::string const&	getTarget( void );

		void	execute( Bureaucrat const& executor ) const;

	private:
		const std::string _target;
		
		PresidentialPardonForm( void );
		PresidentialPardonForm& operator=( PresidentialPardonForm const& rhs );
};

#endif
