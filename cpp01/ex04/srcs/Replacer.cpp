/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:07:25 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 17:10:03 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

Replacer::Replacer( std::string const filename, std::string const s1, std::string const s2)
	: _infileName(filename), _searchedStr(s1), _replacingStr(s2), _replaced(false),
	_fileHandler(filename), _stringReplacer(s1, s2)
{
	std::cout << "\033[33m" << "Replacer: Constructor called" << "\033[0m" <<std::endl;
	return ;
}

Replacer::~Replacer( void )
{
	std::cout << "\033[33m" << "Replacer: Destructor called" << "\033[0m" <<std::endl;
	return ;	
}

/*============================================================================*/
/*       Member functions                                                     */
/*============================================================================*/

int	Replacer::replaceText( void )
{
	if (this->_fileHandler.openInfile() == false || this->_fileHandler.openOutfile() == false)
		return (1);
	this->replaceStrings();
	this->printStatus();
	return (0);
}

void	Replacer::replaceStrings( void )
{
	std::string		line;
	std::ifstream&	inputFile = this->_fileHandler.getInputFile();
	std::ofstream&	outputFile = this->_fileHandler.getOutputFile();
	
	while(std::getline(inputFile, line))
	{
		if (this->_stringReplacer.replaceString(line) == true)
			this->_replaced = true;
		outputFile << line + '\n';
	}
}

void	Replacer::printStatus( void )
{
	if (this->_replaced)
		std::cout << "'" << this->_searchedStr << "' was successfully replaced by '" << this->_replacingStr << "'" << std::endl;
	else
		std::cout << "'" << this->_searchedStr << "' was not found in the file '" << this->_infileName << "'" << std::endl;
}
