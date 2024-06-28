/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:50:38 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/28 10:09:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class	Harl
{
	public:
		/* Constructor & Destructor */
		Harl( void );
		~Harl( void );

		/* Member functions */
		void	complain( std::string level );

	private:
		/* Member functions */
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif
