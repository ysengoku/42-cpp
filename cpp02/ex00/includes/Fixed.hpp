#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

		/* Member functions */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixedNum;
		static const int	_bits = 8; 
};

#endif
