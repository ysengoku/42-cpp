/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:02:11 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 11:02:13 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

Fixed::Fixed( void )
	: _rawBits(0)
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed( const int n )
	: _rawBits(n << Fixed::_fractionalBits)
{
	std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed( const float n )
	: _rawBits(roundf(n * (1 << Fixed::_fractionalBits)))
{
	std::cout << YELLOW << "Float constructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

Fixed &Fixed::operator=( const Fixed& rhs )
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs._rawBits;
	return (*this);
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
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
