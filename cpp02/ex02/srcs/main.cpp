#include "../includes/Fixed.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	test1( void )
{
	std::cout << "TEST 1" << std::endl;
	Fixed	a(5);
	Fixed	b(2.7f);

	std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
	std::cout << (a + b) << " (a + b)" << std::endl;
	std::cout << (a - b) << " (a - b)" << std::endl;
	std::cout << (a * b) << " (a * b)" << std::endl;
	std::cout << (a / b) << " (a / b)" << std::endl;
}

int main( void )
{
	std::cout << CYAN << "======= Test mentionned in the subject  =======" << RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << CYAN << "======= My own tests  =======" << RESET << std::endl;
	test1();
	return (0);
}
