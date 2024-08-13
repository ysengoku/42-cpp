/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:41:43 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/13 11:26:30 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {
	public:
		Array(void);
		Array(unsigned int const& n);
		Array(Array const& src);
		Array& operator=(Array const& rhs);
		~Array(void);

		T& operator[](int index);
		T const& operator[](int index) const;
		unsigned int const& size(void) const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	
	private:
		T *_array;
		unsigned int _size;
};

# include "Array.tpp"

# endif
