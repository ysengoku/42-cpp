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
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
