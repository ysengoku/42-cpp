/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:44:27 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/19 09:44:38 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const& min(T const& a, T const& b) {
	return (a < b ? a : b);
}

template<typename T>
T const& max(T const& a, T const& b) {
	return (a > b ? a : b);
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
