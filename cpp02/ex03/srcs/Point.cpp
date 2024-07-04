#include "../includes/Point.hpp"
#include "Point.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & destructor                                             */
/*============================================================================*/

Point::Point( void )
	: _x(0), _y(0)
{
	//std::cout << YELLOW << "Point: Default constructor called" << RESET << std::endl;
}

Point::Point( const Point& src )
{
	//std::cout << YELLOW << "Point: Copy constructor called" << RESET << std::endl;
	*this = src;
}

Point::~Point( void )
{
	//std::cout << YELLOW << "Point: Destructor called" << RESET << std::endl;
}

Point::Point( const float x,  const float y )
	: _x(x), _y(y)
{
	//std::cout << YELLOW << "Point: Parameterized constructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Copy assignment operator                                             */
/*============================================================================*/

Point &Point::operator=( const Point& rhs )
{
	//std::cout << YELLOW << "Point: Copy assignment operator called but cannot assign const members" << RESET << std::endl;
	this->~Point();
	new (this) Point(rhs._x.toFloat(), rhs._y.toFloat());
	return (*this);
}

/*============================================================================*/
/*       Comparison Operator overload                                         */
/*============================================================================*/

bool	Point::operator==( const Point& rhs ) const
{
	return (this->_x == rhs._x && this->_y == rhs._y);
}

/*============================================================================*/
/*       Member functions                                                     */
/*============================================================================*/

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}
