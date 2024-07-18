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
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	std::cout << MAGENTA << "[BEFORE] " << RESET << std::endl;
	std::cout << "I'm " << dog->getType() << ", ";
	dog->makeSound();
	std::cout << "--- Dog's ideas ---" << std::endl;
	dog->voiceIdea();
	std::cout << "I'm " << cat->getType() << ", ";
	cat->makeSound();
	std::cout << "--- Cat's ideas ---" << std::endl;
	cat->voiceIdea();
	std::cout << MAGENTA << "[AFTER] " << RESET << std::endl;
	std::cout << "I'm " << dog->getType() << ", ";
	dog->makeSound();
	std::cout << "--- Dog's ideas ---" << std::endl;
	dog->replaceIdea("zzzzz", 0);
	dog->voiceIdea();
	std::cout << "I'm " << cat->getType() << ", ";
	cat->makeSound();
	std::cout << "--- Cat's ideas ---" << std::endl;
	cat->replaceIdea("grrrrr", 0);
	cat->voiceIdea();
	delete dog;
	delete cat;
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
