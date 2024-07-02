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
		/* Parameterized Constructor */
		Fixed( const int n );
		Fixed( const float n );
		/* Copy assignment operator */	
		Fixed& operator=( const Fixed& rhs ); 
		/* Destructor */
		~Fixed( void );

		/* Member functions */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_num;
		static const int	_bits = 8; 
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
