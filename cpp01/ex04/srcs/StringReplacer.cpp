/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:42:50 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 17:27:29 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

StringReplacer::StringReplacer( std::string searchedStr, std::string replacingStr )
	: _searchedStr(searchedStr), _replacingStr(replacingStr), _searchedStrLength(searchedStr.length())
{
	std::cout << YELLOW << "StringReplacer: Constructor called" << RESET <<std::endl;
	return ;
}

StringReplacer::~StringReplacer( void )
{
	std::cout << YELLOW << "StringReplacer: Destructor called" << RESET <<std::endl;
	return ;
}

/*============================================================================*/
/*       Member functions                                                     */
/*============================================================================*/

bool	StringReplacer::replaceString( std::string& content )
{
	bool	replaced = false;
	size_t	position;
	char	nextChar;

	position = content.find(this->_searchedStr);
	while (position != std::string::npos)
	{
		if (position + this->_searchedStrLength <= content.length())
		{
			nextChar = content[position + this->_searchedStrLength];
			if (!std::isalnum(nextChar))
			{
				content.erase(position, this->_searchedStrLength);
				content.insert(position, this->_replacingStr);
				replaced = true;
			}
		}
			position = content.find(this->_searchedStr, position + this->_replacingStr.length());
	}
	return (replaced);
}
