/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:05:41 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 16:55:02 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

/*============================================================================*/
/*       Constructor & Destructor                                             */
/*============================================================================*/

FileHandler::FileHandler( std::string infileName )
	: _infileName(infileName), _outfileName(infileName + ".replace")
{
	std::cout << "\033[33m" << "FileHandler: Constructor called" << "\033[0m" <<std::endl;
	return ;
}

FileHandler::~FileHandler( void )
{
	std::cout << "\033[33m" << "FileHandler: Destructor called" << "\033[0m" <<std::endl;
	return ;
}

/*============================================================================*/
/*       Member functions                                                     */
/*============================================================================*/

bool	FileHandler::openInfile( void )
{
	this->_inputFile.open(this->_infileName.c_str(), std::ifstream::in);
	if (!this->_inputFile.is_open())
	{
    	std::cerr << "Failed to open the file: " << this->_infileName << std::endl;
    	return (false);
	}
	return (true);
}

bool	FileHandler::openOutfile( void )
{
	this->_outputFile.open(this->_outfileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!this->_outputFile.is_open())
	{
    	std::cerr << "Failed to open the output file: " << this->_outfileName << std::endl;
		this->_inputFile.close();
    	return (false);
	}
	this->_outputFile.close();
	this->_outputFile.open(this->_outfileName.c_str(), std::ofstream::app);
	if (!this->_outputFile.is_open())
	{
    	std::cerr << "Failed to open the output file: " << this->_outfileName << std::endl;
		this->_inputFile.close();
    	return (false);
	}
	return (true);
}

void	FileHandler::closeFiles( void )
{
	this->_inputFile.close();
	this->_outputFile.close();
}

std::ifstream&	FileHandler::getInputFile( void )
{
	return (this->_inputFile);
}

std::ofstream&	FileHandler::getOutputFile( void )
{
	return (this->_outputFile);
}

std::string const	FileHandler::getInfileName( void )
{
	return (this->_infileName);
}

std::string const	FileHandler::getOutfileName( void )
{
	return (this->_outfileName);
}
