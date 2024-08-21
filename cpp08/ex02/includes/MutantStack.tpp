/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:08:45 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/21 10:36:07 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#define GREY "\e[0;90m"
#define RESET "\033[0m"

template < typename T >
MutantStack< T >::MutantStack(void) {
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

template < typename T >
MutantStack< T >::MutantStack(MutantStack< T > const& src) {
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	this->c = src.c;
}

template < typename T >
MutantStack< T >& MutantStack< T >::operator=(MutantStack< T > const& rhs) {
	std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		std::stack< T >::operator=(rhs);
	return (*this);
}
// Call the copy assignment operator of the base class (std::stack)
// The assignment "*this = rhs" creates a recursive call.

template < typename T >
MutantStack< T >::~MutantStack(void) {
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}
