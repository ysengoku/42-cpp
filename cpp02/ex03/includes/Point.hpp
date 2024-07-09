/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:03:33 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 11:03:35 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "../includes/Fixed.hpp"

class Point
{
	public:
		/* Default constructor */
		Point( void );

		/* Copy constructor */
		Point( const Point& src );

		/* Copy assignment operator */	
		Point& operator=( const Point& rhs ); 

		/* Destructor */
		~Point( void );

		/* Parameterized Constructor */
		Point( const float x,  const float y );

		/* Comparison Operator overload */
		bool	operator==( const Point& rhs ) const;

		/* Member functions */
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif