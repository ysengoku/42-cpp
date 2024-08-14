/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:26:44 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/14 11:24:09 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <cstdlib>
# include <algorithm>

template< template <typename> typename T >
int easyfind(T<int> const& c, int const& n);

class NoOccurrenceException : std::exception {
	virtual const char* what() const throw();
}

# include "easyfind.tpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GREY "\e[0;90m"
# define RESET "\033[0m"

#endif
