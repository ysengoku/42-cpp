/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:02:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/14 10:46:22 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstdlib>

template<typename T>
void iter(T *array, size_t const len, void(*function)(T&)) {
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

/* Overload for functions taking a const argument */
template<typename T>
void iter(T *array, size_t const len, void(*function)(T const&)) {
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GREY "\e[0;90m"
# define RESET "\033[0m"

#endif
