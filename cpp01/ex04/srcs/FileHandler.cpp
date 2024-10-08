/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:05:41 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 14:18:13 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

FileHandler::FileHandler( std::string infileName )
	: _infileName(infileName), _outfileName(infileName + ".replace")
{
	std::cout << YELLOW << "FileHandler: Constructor called" << RESET <<std::endl;
	return ;
}

FileHandler::~FileHandler( void )
{
	std::cout << YELLOW << "FileHandler: Destructor called" << RESET <<std::endl;
	return ;
}

/*============================================================================*/
/*       Member functions                                                     */
/*============================================================================*/

bool	FileHandler::openInfile( void )
{
	this->_ifs.open(this->_infileName.c_str(), std::ios::in);
	if (!this->_ifs.is_open())
	{
    	std::cerr << "Failed to open the file: " << this->_infileName << std::endl;
    	return (false);
	}
	return (true);
}

bool	FileHandler::openOutfile( void )
{
	this->_ofs.open(this->_outfileName.c_str(), std::ios::trunc);
	if (!this->_ofs.is_open())
	{
    	std::cerr << "Failed to open the output file: " << this->_outfileName << std::endl;
		this->_ifs.close();
    	return (false);
	}
	return (true);
}

void	FileHandler::closeFiles( void )
{
	this->_ifs.close();
	this->_ofs.close();
}

std::ifstream&	FileHandler::getInputFile( void )
{
	return (this->_ifs);
}

std::ofstream&	FileHandler::getOutputFile( void )
{
	return (this->_ofs);
}

const std::string	FileHandler::getInfileName( void )
{
	return (this->_infileName);
}

const std::string	FileHandler::getOutfileName( void )
{
	return (this->_outfileName);
}
