/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:14 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/21 10:20:13 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <algorithm>
# include <iterator>
# include <deque>

template< typename T >
class MutantStack : public std::stack< T > {
	public:
		MutantStack(void);
		MutantStack(MutantStack const& src);
		MutantStack< T >& operator=(MutantStack const& rhs);
		~MutantStack(void);

		typedef typename std::stack< T >::container_type::iterator iterator;
		typedef typename std::stack< T >::container_type::const_iterator const_iterator;
		typedef typename std::stack< T >::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack< T >::container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator begin(void) {
			return this->c.begin();
		}
		
		iterator end(void) {
			return this->c.end();
		}

		const_iterator begin(void) const {
			return this->c.begin();
		}
		
		const_iterator end(void) const {
			return this->c.end();
		}

		reverse_iterator rbegin(void) {
			return this->c.rbegin();
		}

		reverse_iterator rend(void) {
			return this->c.rend();
		}

		const_reverse_iterator rbegin(void) const {
			return this->c.rbegin();
		}

		const_reverse_iterator rend(void) const {
			return this->c.rend();
		}
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
