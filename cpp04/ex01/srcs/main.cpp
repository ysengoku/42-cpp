/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:06:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/18 14:58:55 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "../includes/Dog.hpp"
#include "WrongCat.hpp"

#define N  6
	
void	testInSubject( void )
{
	std::cout << CYAN << "====== Tests given in the subject ======" << RESET << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}

void	deepCopyTest( void )
{
	std::cout << std::endl << CYAN << "====== Deep copy tests ======" << RESET << std::endl;
	Dog	dog;
	Dog	dog2(dog);
	Cat cat;
	Cat	cat2(cat);

	std::cout << std::endl << MAGENTA << "[BEFORE] " << RESET << std::endl;
	std::cout << "[Dog]" << std::endl;
	dog.showIdeas();
	std::cout << std::endl << "[Dog copy]"  << std::endl;
	dog2.showIdeas();
	std::cout << std::endl << "[Cat]" << std::endl;
	cat.showIdeas();
	std::cout << std::endl << "[Cat copy]" << std::endl;
	cat2.showIdeas();

	dog2.updateIdea("zzzzz", 0);
	cat2.updateIdea("grrrrr", 0);

	std::cout << std::endl << MAGENTA << "[AFTER] " << RESET << std::endl;
	std::cout << "[Dog]" << std::endl;
	dog.showIdeas();
	std::cout << std::endl << "[Dog copy]" << std::endl;
	dog2.showIdeas();
	std::cout << std::endl << "[Cat]" << std::endl;
	cat.showIdeas();
	std::cout << std::endl << "[Cat copy]" << std::endl;
	cat2.showIdeas();
	std::cout << std::endl;
}

void	shallowCopyTest( void )
{
	std::cout << std::endl << CYAN << "====== Shallow copy tests ======" << RESET << std::endl;
	WrongCat wrongCat;
	WrongCat wrongCat2(wrongCat);

	std::cout << std::endl << MAGENTA << "[BEFORE] " << RESET << std::endl;
	std::cout << "I'm " << wrongCat.getType() << ", ";
	wrongCat.makeSound();
//	wrongCat->showIdeas();

	std::cout << std::endl << MAGENTA << "[AFTER] " << RESET << std::endl;
	std::cout << "I'm " << wrongCat.getType() << ", ";
	wrongCat.makeSound();
//	wrongCat->updateIdea("grrrrr", 0);
//	wrongCat->showIdeas();
}

void	animalsArrayTest( void )
{
	std::cout << std::endl << CYAN << "====== Array of animals tests ======" << RESET << std::endl;
	const Animal *animals[N];
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] " << animals[i]->getType() << " makes sound --> ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < N; i++)
		delete animals[i];
}

int main( void )
{
	testInSubject();
	deepCopyTest();
	animalsArrayTest();
	return (0);
}
