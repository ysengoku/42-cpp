/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:07:25 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 16:36:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

Replacer::Replacer( std::string const filename, std::string const s1, std::string const s2)
	: _infileName(filename), _searchedStr(s1), _replacingStr(s2), _replaced(false),
	_fileHandler(filename), _stringReplacer(s1, s2)
{
	std::cout << YELLOW << "Replacer: Constructor called" << RESET <<std::endl;
	return ;
}

Replacer::~Replacer( void )
{
	std::cout << YELLOW << "Replacer: Destructor called" << RESET <<std::endl;
	return ;	
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

int	Replacer::replaceText( void )
{
	if (this->_fileHandler.openInfile() == false || this->_fileHandler.openOutfile() == false)
		return (1);
	this->replaceStrings();
	this->printStatus();
	return (0);
}

/*============================================================================*/
/*       Private Member functions                                             */
/*============================================================================*/

void	Replacer::replaceStrings( void )
{
	std::string			content;
	std::stringstream	fileContentStream;
	std::ifstream&		ifs = this->_fileHandler.getInputFile();
	std::ofstream&		ouf = this->_fileHandler.getOutputFile();
	
	fileContentStream << ifs.rdbuf();
	content = fileContentStream.str();
	if (this->_stringReplacer.replaceString(content) == true)
		this->_replaced = true;
	ouf << content;
}

void	Replacer::printStatus( void )
{
	if (this->_replaced)
		std::cout << "'" << this->_searchedStr << "' was successfully replaced by '" \
		<< this->_replacingStr << "'" << std::endl;
	else
		std::cout << "'" << this->_searchedStr << "' was not found in the file '" \
		<< this->_infileName << "'" << std::endl;
}
