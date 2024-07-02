#include "Fixed.hpp"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

Fixed::Fixed( void )
{
	std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
}

Fixed::Fixed( const Fixed& src )
	: _fixedNum(src._fixedNum)
{
	std::cout << "\033[33m" << "Copy constructor called" << "\033[0m" << std::endl;
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
		this->_fixedNum = rhs._fixedNum;
	return (*this);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedNum);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedNum = raw;
}
