/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:03:48 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 08:12:43 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "Point.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

Fixed::Fixed( void )
	: _rawBits(0)
{
	//std::cout << YELLOW << "Fixed: Default constructor called" << RESET << std::endl;
}

Fixed::Fixed( const Fixed& src )
{
	//std::cout << YELLOW << "Fixed: Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	//std::cout << YELLOW << "Fixed: Destructor called" << RESET << std::endl;
}

Fixed::Fixed( const int n )
	: _rawBits(n << Fixed::_fractionalBits)
{
	//std::cout << YELLOW << "Fixed: Int constructor called" << RESET << std::endl;
}

Fixed::Fixed( const float n )
	: _rawBits(roundf(n * (1 << Fixed::_fractionalBits)))
{
	//std::cout << YELLOW << "Fixed: Float constructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Copy assignment operator                                             */
/*============================================================================*/

Fixed &Fixed::operator=( const Fixed& rhs )
{
	if (this != &rhs)
		this->_rawBits = rhs._rawBits;
	return (*this);
}

/*============================================================================*/
/*       Comparison Operator overload                                         */
/*============================================================================*/

bool	Fixed::operator>( const Fixed& rhs ) const
{
	return (this->_rawBits > rhs.getRawBits());
}

bool	Fixed::operator<( const Fixed& rhs ) const
{
	return (this->_rawBits < rhs.getRawBits());
}

bool	Fixed::operator>=( const Fixed& rhs ) const
{
	return (this->_rawBits >= rhs.getRawBits());
}

bool	Fixed::operator<=( const Fixed& rhs ) const
{
	return (this->_rawBits <= rhs.getRawBits());
}

bool	Fixed::operator==( const Fixed& rhs ) const
{
	return (this->_rawBits == rhs.getRawBits());
}

bool	Fixed::operator!=( const Fixed& rhs ) const
{
	return (this->_rawBits != rhs.getRawBits());
}

/*============================================================================*/
/*       Arithmetic Operator overload                                         */
/*============================================================================*/

Fixed	Fixed::operator+( const Fixed& rhs ) const
{
	Fixed	result;
	
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator-( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator*( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> Fixed::_fractionalBits);
	return (result);
}

Fixed	Fixed::operator/( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() << Fixed::_fractionalBits) / rhs.getRawBits());
	return (result);
}

/*============================================================================*/
/*       Increment/Decrement Operator overload                                */
/*============================================================================*/

Fixed&	Fixed::operator++( void )
{
	++this->_rawBits;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);

	this->_rawBits++;
	return (tmp);
}

Fixed&	Fixed::operator--( void )
{
	--this->_rawBits;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);

	this->_rawBits--;
	return (tmp);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

int	Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_rawBits) / (1 << Fixed::_fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (this->_rawBits >> Fixed::_fractionalBits);
}

/*============================================================================*/
/*       Overloaded member functions                                          */
/*============================================================================*/

Fixed&	Fixed::min( Fixed& lhs, Fixed& rhs )
{
	if (lhs < rhs)
		return(lhs);
	return (rhs);
}

const Fixed&	Fixed::min( const Fixed& lhs, const Fixed& rhs )
{
	if (lhs < rhs)
		return(lhs);
	return (rhs);
}

Fixed&	Fixed::max( Fixed& lhs, Fixed& rhs )
{
	if (lhs > rhs)
		return(lhs);
	return (rhs);
}

const Fixed&	Fixed::max( const Fixed& lhs, const Fixed& rhs )
{
	if (lhs > rhs)
		return(lhs);
	return (rhs);
}

/*============================================================================*/
/*       Stream Insertion Operator Overload                                   */
/*============================================================================*/

std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
