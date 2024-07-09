/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:42:50 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 16:29:00 by yusengok         ###   ########.fr       */
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

bool	StringReplacer::replaceString( std::string& content )
{
	bool	replaced = false;
	size_t	position;
	char	nextChar;

	position = content.find(this->_searchedStr);
	std::cout << content.length() << std::endl;
	while (position != std::string::npos && position < content.length())
	{
		if (position + this->_searchedStrLength < content.length())
		{
			// Catch replace 'a' by 'aa' case in the text contein only 'a'
			std::cout << position << std::endl;
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
