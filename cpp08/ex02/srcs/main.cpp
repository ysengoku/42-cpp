/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/21 10:50:30 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

void testFromSubject(void);
void emptyTest(void);
void copyTest(void);
void otherTypesTest(void);
void iteratorValidityTest(void);

int main()
{
	testFromSubject();
	emptyTest();
	copyTest();
	otherTypesTest();
	iteratorValidityTest();
	return (0);
}

/*============================================================================*/
/*       Tests definition                                                     */
/*============================================================================*/

void testFromSubject(void) {
	std::cout << std::endl << BGCYAN << " Test from subject " << RESET << std::endl;
	{
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
	{
		std::cout << "--- Same test with list ---" << std::endl;
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
}

void emptyTest(void) {
	std::cout << std::endl << BGCYAN << " Empty MutantStack test " << RESET << std::endl;
	{
		std::cout << CYAN << "begin & end" << RESET << std::endl;
		MutantStack< int > mstack;
		MutantStack< int >::iterator itBegin = mstack.begin();
		MutantStack< int >::iterator itEnd = mstack.end();
		bool result = itBegin == itEnd;
		std::cout << "Resultat: " << result <<  std::endl;
	}
	{
		std::cout << CYAN << "rbegin & rend" << RESET << std::endl;
		MutantStack< int > mstack;
		MutantStack< int >::reverse_iterator itBegin = mstack.rbegin();
		MutantStack< int >::reverse_iterator itEnd = mstack.rend();
		bool result = itBegin == itEnd;
		std::cout << "Resultat: " << result <<  std::endl;
	}
}

void copyTest(void) {
	std::cout << std::endl << BGCYAN << " Copy constructor & copy assignment operator " << RESET << std::endl;
	MutantStack< double > mstack;
	mstack.push(1.2);
	mstack.push(42.0);
	std::cout << "Original: " << std::endl;
	MutantStack< double >::const_iterator it = mstack.begin();
	MutantStack< double >::const_iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl << "Copy constructor: " << std::endl;
	MutantStack< double > copy(mstack);
	MutantStack< double >::const_iterator it2 = copy.begin();
	MutantStack< double >::const_iterator ite2 = copy.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << std::endl << "Copy assignment operator: " << std::endl;
	MutantStack< double > copy2;
	copy2 = mstack;
	MutantStack< double >::const_iterator it3 = copy2.begin();
	MutantStack< double >::const_iterator ite3 = copy2.end();
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
}

void otherTypesTest(void) {
	std::cout << std::endl << BGCYAN << " Test with other types " << RESET << std::endl;
	{
		std::cout << CYAN << "Elements type: char" << RESET << std::endl;
		MutantStack< char > mstack;
		mstack.push('A');
		mstack.push('B');
		std::cout << "< Before pop > top: " << mstack.top();
		std::cout << " | size: " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "< After pop > top: " << mstack.top();
		std::cout << " | Size: " << mstack.size() << std::endl;
		mstack.push('C');
		mstack.push('D');
		mstack.push('E');
		mstack.push('!');
		MutantStack< char >::iterator it = mstack.begin();
		MutantStack< char >::iterator ite = mstack.end();
		while (it !=ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << CYAN << "Elements type: std::string" << RESET << std::endl;
		MutantStack< std::string > mstack;
		mstack.push("Hello");
		mstack.push("Hey");
		std::cout << "< Before pop > top: " << mstack.top();
		std::cout << " | size: " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "< After pop > top: " << mstack.top();
		std::cout << " | Size: " << mstack.size() << std::endl;
		mstack.push("Salut");
		mstack.push("Chao");
		mstack.push("Hola");
		mstack.push("Guten Tag");
		MutantStack< std::string >::iterator it = mstack.begin();
		MutantStack< std::string >::iterator ite = mstack.end();
		while (it !=ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
}

void iteratorValidityTest(void) {
	std::cout << std::endl << BGCYAN << " Iterator test " << RESET << std::endl;
	MutantStack< float > mstack;
	mstack.push(1.1f);
	mstack.push(2.2f);
	mstack.push(3.3f);
	MutantStack< float >::iterator it = mstack.end();
	--it;
	std::cout << *it << std::endl;
	mstack.push(4.4f);
	std::cout << *it << std::endl;
	mstack.pop();
	std::cout << *it << std::endl;
}
