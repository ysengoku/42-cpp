#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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

		/* Parameterized Constructor */
		Fixed( const int n );
		Fixed( const float n );

		/* Member functions */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		/* Comparison Operator overload */
		bool	operator>( const Fixed& rhs ) const;
		bool	operator<( const Fixed& rhs ) const;
		bool	operator>=( const Fixed& rhs ) const;
		bool	operator<=( const Fixed& rhs ) const;
		bool	operator==( const Fixed& rhs ) const;
		bool	operator!=( const Fixed& rhs ) const;

		/* Arithmetic Operator overload */
		Fixed	operator+( const Fixed& rhs ) const;
		Fixed	operator-( const Fixed& rhs ) const;
		Fixed	operator*( const Fixed& rhs ) const;
		Fixed	operator/( const Fixed& rhs ) const;

		/* Increment/Decrement Operator overload */
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		/* Overloaded member functions */
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
