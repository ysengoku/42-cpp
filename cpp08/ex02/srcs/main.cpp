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
void emptyTest(void);

int main()
{
	testMutantStack();
	listCase();
	emptyTest();
	return (0);
}

/*============================================================================*/
/*       Tests definition                                                     */
/*============================================================================*/

void testMutantStack(void) {
	std::cout << std::endl << BGCYAN << " MutantStack test " << RESET << std::endl;
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
	std::cout << std::endl << BGCYAN << " Case with std::list to compare " << RESET << std::endl;
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

void emptyTest(void) {
	std::cout << std::endl << BGCYAN << " Empty MutantStack test " << RESET << std::endl;
	{
		std::cout << "--- begin & end ---" << std::endl;
		MutantStack< int > mstack;
		MutantStack< int >::iterator itBegin = mstack.begin();
		MutantStack< int >::iterator itEnd = mstack.end();
		bool result = itBegin == itEnd;
		std::cout << "Resultat: " << result <<  std::endl;
	}
	{
		std::cout << "--- rbegin & rend ---" << std::endl;
		MutantStack< int > mstack;
		MutantStack< int >::reverse_iterator itBegin = mstack.rbegin();
		MutantStack< int >::reverse_iterator itEnd = mstack.rend();
		bool result = itBegin == itEnd;
		std::cout << "Resultat: " << result <<  std::endl;
	}
}

// Tests with other types of container (list, vector)
// Test with other types than int
// const MutantStack const_iterator tests

/* Iterator validity test
イテレータの取得:
まず、スタックにいくつかの要素を追加します。例えば、1, 2, 3という要素を持つスタックを用意します。
次に、スタックのbegin()イテレータを取得し、これはスタックの最初の要素（この例では1）を指します。
スタック操作の実行:
その後、新たに要素をpush()してスタックに追加したり、pop()してスタックから要素を取り除いたりします。
例えば、push(4)を呼び出して、スタックに4を追加します（スタックの状態は1, 2, 3, 4になります）。
イテレータの確認:
その後、最初に取得したイテレータがまだ正しい要素（この例では1）を指しているか確認します。
一般的には、スタックのpush()操作はイテレータを無効にしないはずです。つまり、push()後もイテレータは同じ要素を指し続けるべきです。
*/