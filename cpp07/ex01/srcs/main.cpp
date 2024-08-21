/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:02:36 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/21 10:42:43 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T> void incrementOne(T& value);
template<typename T> void printValue(T const& value);
void toupperWrapper(char &c);
void writeA(size_t const& n);

void testInt(void) {
	std::cout << CYAN << "===== Test 1 - int/increment =====" << RESET << std::endl; 
	int array[] = {2, 15, -42, 0, 12345};
	size_t len = sizeof(array) / sizeof(int);
	std::cout << "--- BEFORE ---" << std::endl;
	iter(array, len, printValue);

	iter(array, len, incrementOne<int>);

	std::cout << std::endl << "--- AFTER ---" << std::endl;
	iter(array, len, printValue);
	std::cout << std::endl;
}

void testDouble(void) {
	std::cout << CYAN << "===== Test 2 - double/increment =====" << RESET << std::endl; 
	double array[] = {2.5, 15.0, -42.9, 0.25, 12345.123};
	size_t len = sizeof(array) / sizeof(double);
	std::cout << "--- BEFORE ---" << std::endl;
	iter(array, len, printValue);

	iter(array, len, incrementOne<double>);
	
	std::cout << std::endl << "--- AFTER ---" << std::endl;
	iter(array, len, printValue);
	std::cout << std::endl;
}

void testChar(void) {
	std::cout << CYAN << "===== Test 3 - char/increment =====" << RESET << std::endl; 
	char array[] = {'a', 'A', 'z', 'Z', 'k', 'D'};
	size_t len = sizeof(array) / sizeof(char);
	std::cout << "--- BEFORE ---" << std::endl;
	iter(array, len, printValue);

	iter(array, len, incrementOne<char>);
	
	std::cout << std::endl << "--- AFTER ---" << std::endl;
	iter(array, len, printValue);
	std::cout << std::endl;
}

void testChar2(void) {
	std::cout << CYAN << "===== Test 4 - char/toupper =====" << RESET << std::endl; 
	char array[] = {'a', 'A', 'z', 'Z', 'k', '*'};
	size_t len = sizeof(array) / sizeof(char);
	std::cout << "--- BEFORE ---" << std::endl;
	iter(array, len, printValue);

	iter(array, len, toupperWrapper);
	
	std::cout << std::endl << "--- AFTER ---" << std::endl;
	iter(array, len, printValue);
	std::cout << std::endl;
}

void stringToUpper(std::string& str) {
	unsigned int len = str.length();
	for (unsigned int i = 0; i < len; i++)
		str[i] = std::toupper(str[i]);
}

void testString(void) {
	std::cout << CYAN << "===== Test 5 - string/toupper =====" << RESET << std::endl; 
	std::string array[] = {"aaa", "bBb", "CCc!"};
	size_t len = sizeof(array) / sizeof(std::string);
	std::cout << "--- BEFORE ---" << std::endl;
	iter(array, len, printValue);
		
	iter(array, len, stringToUpper);
	
	std::cout << std::endl << "--- AFTER ---" << std::endl;
	iter(array, len, printValue);
	std::cout << std::endl;
}

void testSizeT(void) {
	std::cout << CYAN << "===== Test 6 - size_t =====" << RESET << std::endl; 
	size_t array[] = {2, 15, 0, 5, 20};
	size_t len = sizeof(array) / sizeof(size_t);
	iter(array, len, writeA);
	std::cout << std::endl;
}

int main(void) {
	testInt();
	testDouble();
	testChar();
	testChar2();
	testString();
	testSizeT();
	return 0;
}

/* Functions for tests */
template<typename T>
void incrementOne(T& value) {
	++value;
}

template<typename T>
void printValue(T const& value) {
	std::cout << value << std::endl;
}

void toupperWrapper(char &c) {
	c = std::toupper(c);
}

void writeA(size_t const& n) {
	for (size_t i = 0; i < n; i++)
		std::cout << 'A';
	std::cout << std::endl;
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
