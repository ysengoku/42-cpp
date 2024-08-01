/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:57:39 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/01 16:03:04 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

struct Data
{
	int			id;
	std::string	name;
	double		level;
	bool		isOnLine;

	Data( int id, std::string name, double level, bool isOnLine );
};

std::ostream&	operator<<(std::ostream& os, Data const& data);

#endif