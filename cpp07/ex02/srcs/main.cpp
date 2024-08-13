/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:41:39 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/13 09:14:05 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define CYAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define MAX_VAL 750

void testFromSubject(void)
{
	std::cout << CYAN << "====== Tests from subject & Some additional ones ======" << RESET << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }

    std::cout << "--- Copy constructor & Copy assignment operator ---" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		Array<int> test2;
		test2 = tmp;
    
    	for (int i = 0; i < MAX_VAL; i++)
    	{
    		if (test[i] != tmp[i] || test2[i] != tmp[i])
    		{
            	std::cerr << RED << "Copy failed" << RESET << std::endl;
            	return ;
        	}
    	}
		std::cout << "All values have successfully been copied." << std::endl;
	}

	std::cout << std::endl << "--- Index out of range ---" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

	std::cout << std::endl << "--- Extra tests (deep copy check) ---" << std::endl;
	{
		Array<int> tmp(numbers);
		for (int i = 0; i < 5; i++)
		{
			int index = rand() % MAX_VAL;
			tmp[index] = numbers[index] + 1;
			std::cout << "numbers[" << index << "] " << numbers[index] << std::endl;
			std::cout << "tmp[" << index << "] " << tmp[index] << std::endl;
		}
	}
	{
		Array<int> tmp; 
		tmp = numbers;
		for (int i = 0; i < 5; i++)
		{
			int index = rand() % MAX_VAL;
			tmp [index] = numbers[index] + 1;
			std::cout << "numbers[" << index << "] " << numbers[index] << std::endl;
			std::cout << "tmp[" << index << "] " << tmp[index] << std::endl;
		}
	}
    delete [] mirror;
}

void emptyArray(void) {
	std::cout << std::endl << CYAN << "====== Empty array ======" << RESET << std::endl;
	Array<int> array;
	std::cout << "Array size: " << array.size() << std::endl;
	// std::cout << "Array content: " << array[0] << std::endl;
}

void stringToUpper(std::string& str) {
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
}

void stringArrayTest(void) {
	std::cout << std::endl << CYAN << "====== String array ======" << RESET << std::endl;
	unsigned int arraySize = 3;
	Array<std::string> array(arraySize);
	for (unsigned int i = 0; i < arraySize; i++)
		std::cout << i << ": " << array[i] << std::endl;
	std::cout << "--- Assign values ---" << std::endl;
	array[0] = "Coucou";
	array[1] = "c'est";
	array[2] = "moi !";
	for (unsigned int i = 0; i < arraySize; i++)
		std::cout << i << ": " << array[i] << std::endl;
	std::cout << "--- To upper case ---" << std::endl;
	for (unsigned int i = 0; i < arraySize; i++)
		stringToUpper(array[i]);
	for (unsigned int i = 0; i < arraySize; i++)
		std::cout << i << ": " << array[i] << std::endl;
}

int main(void) {
	testFromSubject();
	emptyArray();
	stringArrayTest();
	return (0);
}
