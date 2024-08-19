/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:00 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/19 16:23:20 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>

class Span {
	public:
		Span(unsigned int N);
		Span(Span const& src);
		Span& operator=(Span const& rhs);
		~Span(void);

		void addNumber(int n);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		template<typename T>
		void addNumbers(T const& nums) {
			for (typename T::const_iterator it = nums.begin(); it != nums.end(); it++)
			addNumber(*it);
		}

		unsigned int getSize(void);

		class NoMoreSpaceException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoElementException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class OnlyOneElementException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::vector<int>	_elements;
		unsigned int		_size;

		Span(void);
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GREY "\e[0;90m"
# define BGCYAN "\033[46m"
# define RESET "\033[0m"

#endif
