/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:28 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/04 10:37:57 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>
# include <exception>
# include <cstdlib>

class RPN {
	private:
		std::stack<long> _stack;
		std::string _input;

		bool isOperator(std::string const&);
		bool isValidNumber(std::string&);
		void performOperation(char token);

		RPN(void);

	public:
		RPN(char* input);
		RPN(RPN const&);
		RPN& operator=(RPN const&);
		~RPN(void);

		void calculate();

		class EmptyInputException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class InvalidValueException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class TooManyOperandsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class TooFewOperandsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class DivisionByZeroException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GREY "\e[0;90m"
# define RESET "\033[0m"

#endif
