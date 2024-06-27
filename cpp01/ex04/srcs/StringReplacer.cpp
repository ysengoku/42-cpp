/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:42:50 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 17:20:37 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

StringReplacer::StringReplacer( std::string searchedStr, std::string replacingStr )
	: _searchedStr(searchedStr), _replacingStr(replacingStr), _searchedStrLength(searchedStr.length())
{
	std::cout << "\033[33m" << "StringReplacer: Constructor called" << "\033[0m" <<std::endl;
	return ;
}

StringReplacer::~StringReplacer( void )
{
	std::cout << "\033[33m" << "StringReplacer: Destructor called" << "\033[0m" <<std::endl;
	return ;
}

/*============================================================================*/
/*       Member functions                                                     */
/*============================================================================*/

bool	StringReplacer::replaceString( std::string& line )
{
	bool	replaced = false;
	size_t	position;
	char	nextChar;

	position = line.find(this->_searchedStr);
	while (position != std::string::npos)
	{
		if (position + this->_searchedStrLength < line.length())
		{
			nextChar = line[position + this->_searchedStrLength];
			if (!std::isalnum(nextChar))
			{
				line.erase(position, this->_searchedStrLength);
				line.insert(position, this->_replacingStr);
				replaced = true;
			}
			position = line.find(this->_searchedStr, position + 1);
		}
	}
	return (replaced);
}
