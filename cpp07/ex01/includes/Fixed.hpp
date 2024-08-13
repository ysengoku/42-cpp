/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:02:45 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/13 11:46:10 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed& src );
		Fixed& operator=( const Fixed& rhs ); 
		~Fixed( void );

		Fixed( const int n );
		Fixed( const float n );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator>( const Fixed& rhs ) const;
		bool	operator<( const Fixed& rhs ) const;
		bool	operator>=( const Fixed& rhs ) const;
		bool	operator<=( const Fixed& rhs ) const;
		bool	operator==( const Fixed& rhs ) const;
		bool	operator!=( const Fixed& rhs ) const;

		Fixed	operator+( const Fixed& rhs ) const;
		Fixed	operator-( const Fixed& rhs ) const;
		Fixed	operator*( const Fixed& rhs ) const;
		Fixed	operator/( const Fixed& rhs ) const;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		static Fixed&		min( Fixed& lhs, Fixed& rhs );
		static const Fixed&	min( const Fixed& lhs, const Fixed& rhs );
		static Fixed&		max( Fixed& lhs, Fixed& rhs );
		static const Fixed&	max( const Fixed& lhs, const Fixed& rhs );

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8; 
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
