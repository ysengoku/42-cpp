/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:06:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/17 13:44:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	testInSubject( void )
{
	std::cout << CYAN << "====== Tests given in the subject ======" << RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
}

void	wrongCatTest( void )
{
	std::cout << std::endl << CYAN << "====== WrongCat test ======" << RESET << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "--- WrongCat ---" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	std::cout << "--- WrongAnimal ---" << std::endl;
	meta->makeSound();
	delete meta;
	delete wrongCat;
}

void	additionalTests( void )
{
	std::cout << std::endl << CYAN << "====== My own tests ======" << RESET << std::endl;

	std::cout << std::endl << "------ Cat as Animal ------" << std::endl;
	const Animal *cat = new Cat();
	std::cout << cat->getType() << " makes sound: ";
	cat->makeSound();
	delete cat;

	std::cout << std::endl << "------ Cat as Cat ------" << std::endl;
	const Cat *cat2 = new Cat();
	std::cout << cat2->getType() << " makes sound: ";
	cat2->makeSound();
	delete cat2;

	std::cout << std::endl << "------ Dog as Animal ------" << std::endl;
	const Animal *dog = new Dog();
	std::cout << dog->getType() << " makes sound: ";
	dog->makeSound();
	delete dog;

	std::cout << std::endl << "------ Dog as Dog ------" << std::endl;
	const Dog *dog2 = new Dog();
	std::cout << dog2->getType() << " makes sound: ";
	dog2->makeSound();
	delete dog2; 
}

int main( void )
{
	testInSubject();
	wrongCatTest();
	additionalTests();
	return (0);
}
