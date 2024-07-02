#include "Fixed.hpp"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

Fixed::Fixed( void )
	: _num(0)
{
	std::cout << "\033[33m" << "Default constructor called" << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed& src )
	: _num(src._num)
{
	std::cout << "\033[33m" << "Copy constructor called" << "\033[0m" << std::endl;
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "\033[33m" << "Destructor called" << "\033[0m" << std::endl;
	return ;
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

Fixed &Fixed::operator=( const Fixed& rhs )
{
	std::cout << "\033[33m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &rhs)
		this->_num = rhs._num;
	return (*this);
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

int	Fixed::getRawBits( void ) const
{
	std::cout << "\033[33m" << "getRawBits member function called"  << "\033[0m" << std::endl;
	return (this->_num);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "\033[33m" << "setRawBits member function called"  << "\033[0m" << std::endl;
	this->_num = raw;
	return ;
}
