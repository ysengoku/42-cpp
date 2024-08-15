/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:26:47 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/14 14:04:23 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

# define RED "\033[31m"
# define RESET "\033[0m"

template< typename T >
int easyfind(T const& intContainer, int const& to_find) {
	typename T::const_iterator it = std::find(intContainer.begin(), intContainer.end(), to_find);
	if (it == intContainer.end())
		throw NoOccurrenceException();
	return (*it);
}

const char* NoOccurrenceException::what() const throw() {
	return (RED "No occurrence is found." RESET);
}
