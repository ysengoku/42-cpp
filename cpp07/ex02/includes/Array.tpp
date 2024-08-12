/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:40:08 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/12 17:04:01 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define GREY "\e[0;90m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

template<typename T>
Array<T>::Array(void) : _size(0) {
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
	this->_array = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int const &n) : _size(n) {
	std::cout << GREY << "Constructor called" << RESET << std::endl;
	this->_array = new T[static_cast<int>(this->_size)];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = 0;
}

template<typename T>
Array<T>::Array(Array const& src) : _size(src._size) {
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < src._size; i++)	
		this->_array[i] = src._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& rhs) {
	std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		delete[] this->_array;
		this->_size = rhs._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array(void) {
	std::cout << GREY << "Destructor called" << RESET << std::endl;
	delete[] _array;
}

/*============================================================================*/
/*       Member functions                                                     */
/*============================================================================*/

template<typename T>
unsigned int const& Array<T>::size(void) const {
	return (this->_size);
}

/*============================================================================*/
/*       Operator overload                                                    */
/*============================================================================*/

template<typename T>
T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= static_cast<int>(this->_size))
		throw OutOfBoundsException();
	return (this->_array[index]);
}

/*============================================================================*/
/*       Exceptions                                                           */
/*============================================================================*/

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return ("ERROR: The index is out of bounds.");
}
