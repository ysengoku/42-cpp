#include "Fixed.hpp"

void	test(int raw)
{
	Fixed a;
	a.setRawBits(raw);

	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;
}

int main( void )
{
	std::cout << "\033[36m======= Test1 (raw = 0) =======\033[0m" << std::endl;
	test(0);
	std::cout << std::endl << "\033[36m======= Test2 (raw = 42) =======\033[0m" << std::endl << std::endl;
	test(42);
	std::cout << std::endl << "\033[36m======= Test3 (raw = -5) =======\033[0m" << std::endl;
	test(-5);
	return (0);
}
