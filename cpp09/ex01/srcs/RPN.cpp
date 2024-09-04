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
		this->_stack = rhs._stack;
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

void RPN::calculate(void) {
	std::istringstream	iss(_input);
	std::string			token;
	char				*p_end;

	if (_input.empty())
		throw EmptyInputException();
	while (iss >> token) {
		if (isOperator(token)) {
			try {
				performOperation(token[0]);
			}
			catch(const std::exception& e) {
				std::cerr << e.what();
				return;
			}
		}
		else if (isValidNumber(token))
			_stack.push(strtol(token.c_str(), &p_end, 10));
		else
			throw InvalidValueException();
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw TooManyOperandsException();
}

/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

bool RPN::isOperator(std::string const& token) {
	if (token == "+" || token == "-" || token == "/" || token == "*")
		return (true);
	return (false);
}

bool RPN::isValidNumber(std::string& token) {
	if (token.length() > 2)
		return (false);
	std::string::iterator it = token.begin();
	std::string::iterator ite = token.end();
	while (it != ite) {
		if (!(isdigit(*it) || *it == '-'))
			return (false);
		++it;
	}
	if (atoi(token.c_str()) > 10 || atoi(token.c_str()) < -10)
		return (false);
	return (true);
}

void RPN::performOperation(char token) {
	long res;
	long operand1;
	long operand2;

	if (_stack.size() < 2)
		throw TooFewOperandsException();
	operand2 = _stack.top();
	_stack.pop();
	operand1 = _stack.top();
	_stack.pop();
	switch (token) {
		case '+':
			res = operand1 + operand2;
			break ;
		case '-':
			res = operand1 - operand2;
			break ;
		case '/':
			if (operand2 == 0)
				throw DivisionByZeroException();
			res = operand1 / operand2;
			break ;
		case '*':
			res = operand1 * operand2;
			break ;
	}
	_stack.push(res);
}

/*============================================================================*/
/*       Exceptions                                                           */
/*============================================================================*/

const char* RPN::EmptyInputException::what() const throw() {
	return (RED "Error: Input is empty.\n" RESET);
}

const char* RPN::InvalidValueException::what() const throw() {
	return (RED "Error: Invalid value detected in the input expression.\n" RESET);
}

const char* RPN::TooManyOperandsException::what() const throw() {
	return (RED "Error: Extra operand(s) detected.\n" RESET);
}

const char* RPN::TooFewOperandsException::what() const throw() {
	return (RED "Error: Insufficient operands for operation.\n" RESET);
}

const char* RPN::DivisionByZeroException::what() const throw() {
	return (RED "Error: Division by zero cannot be performed.\n" RESET);
}
