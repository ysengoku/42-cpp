/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:52:11 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/01 16:05:07 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

Serializer::Serializer( void ) {}

Serializer::Serializer( Serializer const& src ) {(void)src;}

Serializer& Serializer::operator=( Serializer const& rhs ) { (void)rhs; return (*this);}

Serializer::~Serializer( void ) {}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

uintptr_t	Serializer::serialize(Data* ptr)
{
	void		*tmp = static_cast<void*>(ptr);
	uintptr_t	res = reinterpret_cast<uintptr_t>(tmp);
	return (res);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	void	*tmp = reinterpret_cast<void*>(raw);
	Data	*res = static_cast<Data*>(tmp);
	return (res);
}
