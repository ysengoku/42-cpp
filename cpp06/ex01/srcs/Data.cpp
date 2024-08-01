/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:46:23 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/01 16:03:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( int id, std::string name, double level, bool isOnLine ) 
	: id(id), name(name), level(level), isOnLine(isOnLine) {};

std::ostream&	operator<<(std::ostream& os, Data const& data)
{
	os << std::endl << "Data content" << std::endl
	<< "id: " << data.id << std::endl
	<< "name: " << data.name << std::endl
	<< "level: " << data.level << std::endl
	<< "isOnLine: " << data.isOnLine << std::endl;
	return (os);
}
