/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:06:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 11:11:02 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define N  6
#define IDEAS_COUNT 4
#define DOG_IDEAS "Play!", "I'm hungry.", "I'm sleepy.", "Let's go for a Walk?"
#define CAT_IDEAS "Food dish is empty!", "Nap time?", "This is my place.", "Who is he?"
	
void	testInSubject( void )
{
	std::cout << CYAN << "====== Tests given in the subject ======" << RESET << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;
}

void	deepCopyTest( void )
{
	{
		std::cout << std::endl << CYAN << "====== Deep copy tests Dog ======" << RESET << std::endl;
		Dog	dog;
		std::string dogIdeas[IDEAS_COUNT] = {DOG_IDEAS};
		for (int i = 0; i < IDEAS_COUNT; i++)
			dog.setIdeaToBrain(dogIdeas[i], i);
		Dog	dog2(dog);

		std::cout << std::endl << MAGENTA << "[BEFORE] " << RESET << std::endl;
		std::cout << "🐶 Dog" << std::endl;
		for (int i = 0; i < IDEAS_COUNT; i++)
			dog.showIdea(i);
		std::cout << std::endl << "🐶 Dog copy"  << std::endl;
		for (int i = 0; i < IDEAS_COUNT; i++)
			dog2.showIdea(i);

		dog2.setIdeaToBrain("zzzzz", 0);

		std::cout << std::endl << MAGENTA << "[AFTER] " << RESET << std::endl;
		std::cout << "🐶 Dog" << std::endl;
		for (int i = 0; i < IDEAS_COUNT; i++)
			dog.showIdea(i);
		std::cout << std::endl << "🐶 Dog copy" << std::endl;
		for (int i = 0; i < IDEAS_COUNT; i++)
			dog2.showIdea(i);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << CYAN << "====== Deep copy tests Cat ======" << RESET << std::endl;
		Cat cat;
		std::string catIdeas[IDEAS_COUNT] = {CAT_IDEAS};
		for (int i = 0; i < IDEAS_COUNT; i++)
			cat.setIdeaToBrain(catIdeas[i], i);
		Cat	cat2(cat);

		std::cout << std::endl << MAGENTA << "[BEFORE] " << RESET << std::endl;
		std::cout << "🐱 Cat" << std::endl;
		for (int i = 0; i < IDEAS_COUNT; i++)
			cat.showIdea(i);
		std::cout << std::endl << "🐱 Cat copy" << std::endl;
		for (int i = 0; i < IDEAS_COUNT; i++)
			cat2.showIdea(i);

		cat2.setIdeaToBrain("grrrrr", 0);
	
		std::cout << std::endl << MAGENTA << "[AFTER] " << RESET << std::endl;
		std::cout << "🐱 Cat" << std::endl;
		for (int i = 0; i < IDEAS_COUNT; i++)
			cat.showIdea(i);
		std::cout << std::endl << "🐱 Cat copy" << std::endl;
		for (int i = 0; i < IDEAS_COUNT; i++)
			cat2.showIdea(i);
		std::cout << std::endl;
	}
	std::cout << std::endl << CYAN << "====== Another deep copy test ======" << RESET << std::endl;
	Dog	a;
	{
		Dog tmp = a;
	}
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
	deepCopyTest();
	animalsArrayTest();
	return (0);
}
