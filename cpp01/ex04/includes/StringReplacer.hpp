/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:41:08 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 17:18:54 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGREPLACER_HPP
# define STRINGREPLACER_HPP

# include <iostream>
# include <string>

class StringReplacer
{
	public:
		/* Constructor & Destructor */
		StringReplacer( std::string searchedStr, std::string replacingStr );
		~StringReplacer( void );

		/* Member functions */
		bool	replaceString( std::string& line );

	private:
		std::string&	_searchedStr;
		std::string&	_replacingStr;
		size_t			_searchedStrLength;
};

# endif
