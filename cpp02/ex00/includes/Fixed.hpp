/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:01:13 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 11:01:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		/* Default constructor */
		Fixed( void );

		/* Copy constructor */
		Fixed( const Fixed& src );

		/* Copy assignment operator */	
		Fixed& operator=( const Fixed& rhs ); 

		/* Destructor */
		~Fixed( void );

		/* Member functions */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8; 
};

#endif
