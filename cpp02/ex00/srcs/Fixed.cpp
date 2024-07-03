#include "Fixed.hpp"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

Fixed::Fixed( void )
	: _rawBits(0)
{
	std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << "\033[33m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	std::cout << "\033[33m" << "Destructor called" << "\033[0m" << std::endl;
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

Fixed &Fixed::operator=( const Fixed& rhs )
{
	std::cout << "\033[33m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs._rawBits;
	return (*this);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

int	Fixed::getRawBits( void ) const
{
	std::cout << "\033[33m" << "getRawBits member function called"  << "\033[0m" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "\033[33m" << "setRawBits member function called"  << "\033[0m" << std::endl;
	this->_rawBits = raw;
}
