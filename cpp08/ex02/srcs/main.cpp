/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/20 15:12:27 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void testMutantStack(void); // From subject
void listCase(void);

int main()
{
	testMutantStack();
	listCase();
	return (0);
}

/*============================================================================*/
/*       Tests definition                                                     */
/*============================================================================*/

void testMutantStack(void) {
	std::cout << BGCYAN << " MutantStack test " << RESET << std::endl;
	MutantStack< int > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack< int >::iterator it = mstack.begin();
	MutantStack< int >::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack< int >  s(mstack);
}

void listCase(void) {
	std::cout << BGCYAN << " Case with std::list to compare " << RESET << std::endl;
	std::list < int > test;
	test.push_back(5);
	test.push_back(17);
	std::cout << *(test.rbegin()) << std::endl;
	test.pop_back();
	std::cout << test.size() << std::endl;
	test.push_back(3);
	test.push_back(5);
	test.push_back(737);
	test.push_back(0);
	std::list< int >::iterator it = test.begin();
	std::list< int >::iterator ite = test.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}
