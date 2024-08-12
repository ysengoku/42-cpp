/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:41:39 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/12 17:03:45 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define CYAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define MAX_VAL 750

void testFromSubject(void)
{
	std::cout << CYAN << "====== Tests from subject ======" << RESET << std::endl;
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
            std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
            return ;
        }
    }

    std::cout << "--- Copy constructor & copy assignment operator ---" << std::endl;
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

	std::cout << std::endl << "--- Negative index value ---" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl << "--- Too big index value ---" << std::endl;
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

	std::cout << std::endl << "--- Extra tests by me ---" << std::endl;
	{
		Array<int> tmp(numbers);
		for (int i = 0; i < 5; i++)
		{
			int index = rand() % MAX_VAL;
			tmp [index] = numbers[index] + 1;
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
	// std::cout << "Array content: " << array[0] << std::endl;
}

int main(void) {
	testFromSubject();
	emptyArray();
	return (0);
}