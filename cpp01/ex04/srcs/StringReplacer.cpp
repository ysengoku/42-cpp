/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:42:50 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 11:12:07 by yusengok         ###   ########.fr       */
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

// bool	StringReplacer::replaceString( std::string& content )
// {
// 	bool	replaced = false;
// 	size_t	position;
// 	char	nextChar;

// 	position = content.find(this->_searchedStr);
// 	while (position != std::string::npos)
// 	{
// 		nextChar = content[position + this->_searchedStrLength];
// 		if (position + this->_searchedStrLength < content.length()
// 		|| (position + this->_searchedStrLength == content.length() && !std::isalnum(nextChar)))
// 		{
// 			if (!std::isalnum(nextChar) && !std::isalnum(content[position - 1]))
// 			{
// 				content.erase(position, this->_searchedStrLength);
// 				content.insert(position, this->_replacingStr);
// 				replaced = true;
// 			}
// 			position = content.find(this->_searchedStr, position + this->_replacingStr.length());
// 		}
// 	}
// 	return (replaced);
// }

void	StringReplacer::replaceString( std::string& content )
{
	bool		replaced = false;
	std::string	result;
	size_t		position = 0;
	size_t		nextPosition = content.find(this->_searchedStr, position);

	while (nextPosition != std::string::npos)
	{
		result += content.substr(position, nextPosition - position);
		result += this->_replacingStr;
		replaced = true;
		position = nextPosition + this->_searchedStrLength;
		nextPosition = content.find(this->_searchedStr, position);
	}
	result += content.substr(position);
	if (replaced)
	{
		content = result;
		std::cout << "'" << this->_searchedStr << "' was successfully replaced by '" \
		<< this->_replacingStr << "'." << std::endl;
	}
	else
		std::cout << "'" << this->_searchedStr << "' was not found in the file."<< std::endl;
}
