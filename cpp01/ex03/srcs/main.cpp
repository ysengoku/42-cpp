#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void	test1( void )
{
	std::cout << "\033[36m===== Test 1: Both Humans have weapon =====\033[0m" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("warhammer club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("studded club");
		jim.attack();
	}
}

void	test2( void )
{
	std::cout << "\033[36m===== Test 2: HumanB has no weapon =====\033[0m" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("flanged mace");
		bob.attack();
	}
	{
		HumanB jim("Jim");
		jim.attack();
		jim.attack();
	}
}

int main()
{
	test1();
	test2();
	return (0);
}
