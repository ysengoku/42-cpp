#include "Fixed.hpp"

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

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

int	Fixed::getRawBits( void ) const
{
	std::cout << YELLOW << "getRawBits member function called"  << RESET << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << YELLOW << "setRawBits member function called"  << RESET << std::endl;
	this->_rawBits = raw;
}
