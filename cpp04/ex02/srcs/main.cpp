/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:06:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 11:07:48 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define N  6
	
void	testInSubject( void )
{
	std::cout << CYAN << "====== Tests given in the subject ======" << RESET << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;
}

void	animalsArrayTest( void )
{
	std::cout << std::endl << CYAN << "====== Array of animals tests ======" << RESET << std::endl;
	const AAnimal *animals[N];
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
	// AAnimal aanimal(); // "AAnimal" is not instantiable
	
	testInSubject();
	animalsArrayTest();
	return (0);
}
