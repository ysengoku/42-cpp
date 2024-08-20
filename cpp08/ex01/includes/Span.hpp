/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:00 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/20 09:25:12 by yusengok         ###   ########.fr       */
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
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

		template<typename T>
		void addRange(typename T::const_iterator first, typename T::const_iterator last) {
			size_t distance = std::distance(first, last);
			if (distance > _size - _elements.size())
				throw NoMoreSpaceException();
			_elements.insert(_elements.end(), first, last);
		}

		void printElements(void) const;

		class NoMoreSpaceException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class TooFewElementException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::vector< int >	_elements;
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
