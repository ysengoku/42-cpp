/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN::RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:35 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/02 09:20:06 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

RPN::RPN(void) {
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

RPN::RPN(char* input) : _input(input) {
	std::cout << GREY << "Constructor called" << RESET << std::endl;
}

RPN::RPN(RPN const& src) {
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

RPN& RPN::operator=(RPN const& rhs) {
	std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs) {
		this->_data = rhs._data;
		this->_input = rhs._input;
	}
	return (*this);
}

RPN::~RPN() {
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

int RPN::calculate(void) {
	int resultat;
	
	return (resultat);
}

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

bool RPN::isInputNumeric(void) {

}
