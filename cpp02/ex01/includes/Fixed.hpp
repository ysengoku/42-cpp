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

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8; 
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
