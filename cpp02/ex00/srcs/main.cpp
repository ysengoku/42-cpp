#include "Fixed.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

void	test(int raw)
{
	Fixed a;
	a.setRawBits(raw);

	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

int main( void )
{
	std::cout << CYAN << "======= Test mentionned in the subject  =======" << RESET << std::endl;
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << CYAN << "======= My own tests  =======" << RESET << std::endl;
	std::cout << "TEST raw = 42" << std::endl;
	test(42);
	std::cout << std::endl << "TEST raw = -5" << std::endl;
	test(-5);
	return (0);
}
