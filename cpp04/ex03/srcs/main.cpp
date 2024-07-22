/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:15:27 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/22 15:12:17 by yusengok         ###   ########.fr       */
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

void	deepCopyTest( void )
{
	std::cout << CYAN << "====== TEST: deep copy ======" << RESET << std::endl;
	Character me;
	{
		Character tmp = me;
	}
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
	ICharacter* sam = new Character("sam");
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
		me->use(i, *sam);

	delete sam;
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
	ICharacter* sam = new Character("sam");
	AMateria* tmp;

	std::cout << BLUE << "--- Try use() before equip() ---" << RESET << std::endl;
	me->use(0, *sam);
	
	std::cout << BLUE << "--- equip() 'ice' ---" << RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	std::cout << BLUE << "--- Use index 0 ---" << RESET << std::endl;
	me->use(0, *sam);
	std::cout << BLUE << "--- Unequip index 0 ---" << RESET << std::endl;
	me->unequip(0);
	std::cout << BLUE << "--- Use index 0 ---" << RESET << std::endl;
	me->use(0, *sam);
	std::cout << BLUE << "--- Use index 2 ---" << RESET << std::endl;
	me->use(2, *sam);
	std::cout << BLUE << "--- Unequip index 2 ---" << RESET << std::endl;
	me->unequip(2);

	std::cout << BLUE << "--- equip 'cure' & use it ---" << RESET << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *sam);

	delete sam;
	delete me;
	delete src;
}

void	materiaSourceTest( void )
{
	std::cout << CYAN << "====== TEST: materia source ======" << RESET << std::endl;
	IMateriaSource *src = new MateriaSource();
	
	std::cout << BLUE << "--- Learn 4 times ---" << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << BLUE << "--- 5th learn ---" << RESET << std::endl;
	AMateria *tmp5 = new Ice();
	src->learnMateria(tmp5);
	delete tmp5;
	
	delete src;
}

int main( void )
{
	testInSubject();
	deepCopyTest();
	equipTest();
	unequipTest();
	materiaSourceTest();
  	return (0);
}
