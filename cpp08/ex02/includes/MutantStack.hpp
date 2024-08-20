/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:14 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/20 15:38:58 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <algorithm>
# include <iterator>
# include <deque>

template< typename T, typename Container = std::deque< T > >
class MutantStack : public std::stack< T > {
	public:
		// typedef std::iterator< std::input_iterator_tag, T > iterator = typename Container::iterator< T >;
		// using iterator = typename Container::iterator;

		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		
		// class iterator : public std::iterator< std::input_iterator_tag, T >
		// 										// T,			// value_type
        //                         				// std::ptrdiff_t, // difference_type
        //                         				// T*,				// pointer
        //                         				// T& >			// reference
		// {
		// 	public:
		// 		iterator& operator++(void);
		// 		iterator& operator--(void);
		// 		iterator operator++(int);
		// 		iterator operator--(int);
		// 		bool operator==(iterator const& rhs);
		// 		bool operator!=(iterator const& rhs);				
		// 		T& operator*(void) const;
		// };

		
		iterator begin(void) const {
			// return c.begin();

		}
		
		iterator end(void) const {
			return 0;
		}
		// rbegin
		// rend
};

# include "MutantStack.tpp"

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
