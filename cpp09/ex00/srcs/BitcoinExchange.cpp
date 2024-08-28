/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:31:58 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/28 12:36:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

BitcoinExcange::BitcoinExcange(void) {}

BitcoinExcange::BitcoinExcange(BitcoinExcange const& src) {
	
}

BitcoinExcange& BitcoinExcange::operator=(BitcoinExcange const& rhs) {

}

BitcoinExcange::~BitcoinExcange(void) {
	
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void BitcoinExcange::readDatabase(void) {
	std::ifstream ifs(DATABASE);
	std::string key;
	std::string valueStr;
	float value;
	char delimiter = ',';

	if (!ifs.is_open())
		throw FileOpenErrorException();
	while (ifs >> key >> delimiter >> valueStr) {
		// try 
		// value = strToFloat(valueStr);
		this->_database.insert(std::pair<std::string, float>(key, value));
	}
}

void BitcoinExcange::openInputFile(char* filename) {
	this->_ifs.open(filename, std::ios::in);
	if (!this->_ifs.is_open())
		throw FileOpenErrorException();
}


	// std::string content;
	// std::stringstream fileContentStream;	
	// fileContentStream << this->_ifs.rdbuf();
	// content = fileContentStream.str();
	
/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

float BitcoinExcange::strToFloat(std::string const& str) {
	char *end;
	float num;
	errno = 0;
	
	double tmp = std::strtod(str.c_str(), &end);
	num = static_cast<float>(tmp);
	if (errno == ERANGE || num > FLOAT_MAX || num < 0)
		throw InvalidValueException();
	return (num);
}

/*============================================================================*/
/*       Exceptions                                                           */
/*============================================================================*/

const char* BitcoinExcange::FileOpenErrorException::what() const throw() {
	return ("Error: could not open file");
}

const char* BitcoinExcange::InvalidValueException::what() const throw() {
	return ("Error: Invalid value");
}
