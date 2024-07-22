/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:15:27 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/22 13:49:34 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	testInSubject( void )
{
	std::cout << CYAN << "====== Tests given in the subject ======" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	equipTest( void )
{
	std::cout << CYAN << "====== TEST: equip() function ======" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");
	AMateria* tmp;

	std::cout << BLUE << "--- 1st equip() ---" << RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << BLUE << "--- 2nd equip() ---" << RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << BLUE << "--- 3rd equip() ---" << RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << BLUE << "--- 4th equip() ---" << RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << BLUE << "--- 5th equip() ---" << RESET << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete (tmp);
	
	std::cout << BLUE << "--- Let's use them ---" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		me->use(i, *you);

	delete you;
	delete me;
	delete src;
}

void	unequipTest( void )
{
	std::cout << CYAN << "====== TEST: unequip() & use() function ======" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");
	AMateria* tmp;

	std::cout << BLUE << "--- Try use() before equip() ---" << RESET << std::endl;
	me->use(0, *you);
	
	std::cout << BLUE << "--- equip() 0 & 1 ---" << RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << BLUE << "--- Use index 0 ---" << RESET << std::endl;
	me->use(0, *you);
	std::cout << BLUE << "--- Unequip index 0 ---" << RESET << std::endl;
	me->unequip(0);
	std::cout << BLUE << "--- Use index 2 ---" << RESET << std::endl;
	me->use(2, *you);
	std::cout << BLUE << "--- Unequip index 2 ---" << RESET << std::endl;
	me->unequip(2);

	delete you;
	delete me;
	delete src;
}

// void	learnMateriaCheck( void )
// {
// 	IMateriaSource *src = new MateriaSource();
// 	AMateria *tmp = new Ice();
// 	AMateria *tmp2 = new Ice();
// 	src->learnMateria(tmp);
// 	src->learnMateria(tmp);
// 	src->learnMateria(tmp2);
// 	delete src;
// }

int main( void )
{
	testInSubject();
	equipTest();
	unequipTest();
  	return (0);
}
