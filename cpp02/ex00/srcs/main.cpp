#include "Fixed.hpp"

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
	std::cout << "\033[36m======= Test mentionned in the subject  =======\033[0m" << std::endl;
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "\033[36m======= My own tests  =======\033[0m" << std::endl;
	std::cout << "TEST raw = 42" << std::endl;
	test(42);
	std::cout << std::endl << "TEST raw = -5" << std::endl;
	test(-5);
	return (0);
}
