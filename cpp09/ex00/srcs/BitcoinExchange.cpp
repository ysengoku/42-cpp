/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:31:58 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/29 15:00:22 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*============================================================================*/
/*       Constructor / destructor / Copy assignment operator                  */
/*============================================================================*/

BitcoinExcange::BitcoinExcange(char* inputFileName) : _inputFileName(inputFileName) {
	if (readDatabase() == false)
		exit(1);
	_ifs.open(_inputFileName, std::ios::in);
	if (!_ifs.is_open()) {
		std::cout << "Error: could not open inputfile file" << std::endl;
		exit(1);
	}
	setTodaysDate();
	std::cout << GREY << "Constructor called" << RESET << std::endl;
}

BitcoinExcange::BitcoinExcange(BitcoinExcange const& src)
: _database(src._database), _inputFileName(src._inputFileName), _today(src._today) {
	this->_ifs.open(_inputFileName, std::ios::in);
	if (!this->_ifs.is_open()) {
		std::cout << "Error: could not open inputfile file" << std::endl;
		exit(1);
	}	
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
}

BitcoinExcange& BitcoinExcange::operator=(BitcoinExcange const& rhs) {
	if (this != &rhs) {
		this->_database = rhs._database;
		this->_inputFileName = rhs._inputFileName;
		this->_today = rhs._today;
		this->_ifs.open(_inputFileName, std::ios::in);
		if (!this->_ifs.is_open()) {
			std::cout << "Error: could not open inputfile file" << std::endl;
			exit(1);
		}
	}
	std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

BitcoinExcange::~BitcoinExcange(void) {
	std::cout << GREY << "Destructor called" << RESET << std::endl;
	this->_ifs.close();
}

BitcoinExcange::BitcoinExcange(void) {
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

/*============================================================================*/
/*       Public member functions                                              */
/*============================================================================*/

void BitcoinExcange::exchange(void) {
	std::string line;
	char delimiter = '|';
	
	while (std::getline(_ifs, line)) {
		if (line == "date | value")
			continue ;
			
		std::istringstream iss(line);
		std::string date;
		std::string amountStr;
		float amount;
		float rate;

		std::getline(iss, date, delimiter);
		std::getline(iss, amountStr);
		if (!checkDate(date) || !checkAmount(amountStr))
			continue ;
		amount = static_cast<float>(std::atof(amountStr.c_str()));
		rate = findRate(date); 
		std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
	}
	this->_ifs.close();		
} 
	
/*============================================================================*/
/*       Private member functions                                             */
/*============================================================================*/

void BitcoinExcange::setTodaysDate(void) {
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
	char buffer[11];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &datetime);
	_today = std::string(buffer);
}

bool BitcoinExcange::readDatabase(void) {
	std::ifstream ifs(DATABASE);
	std::string line;
	char delimiter = ',';

	if (!ifs.is_open()) {
		std::cout << "Error: could not open database file" << std::endl;
		return (false);	
	}
	while (std::getline(ifs, line)) {
		std::istringstream iss(line);
		std::string key;
		std::string valueStr;
		float value;
		
		std::getline(iss, key, delimiter);
		if (key == "date")
			continue ;
		std::getline(iss, valueStr);
		value = static_cast<float>(std::atof(valueStr.c_str()));
		this->_database.insert(std::pair<std::string, float>(key, value));
	}	
	ifs.close();
	return (true);
}

bool BitcoinExcange::checkDate(std::string const& date) {
	std::istringstream iss(date);
	std::string yearStr;
	std::string monthStr;
	std::string dayStr;
	char delimiter = '-';

	if (date.empty()) 
		return (false);
	if (date > _today) {
		std::cout << "Error: Bad input => " << date << std::endl;
		return (false);
	}
	std::getline(iss, yearStr, delimiter);
	std::getline(iss, monthStr, delimiter);
	std::getline(iss, dayStr);
	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
		std::cout << "Error: Bad input => " << date << std::endl;
		return (false);
	}
	// Check April, June, September and Novermber
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
		std::cout << "Error: Bad input => " << date << std::endl;
		return (false);
	}
	// Check February
	if (month == 2 && (day >= 30 || (year % 4 != 0 && day == 29))) {
		std::cout << "Error: Bad input => " << date << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExcange::checkAmount(std::string const& amount) {
	char *end;
	float num;
	errno = 0;
	
	double tmp = std::strtod(amount.c_str(), &end);
	if (amount.empty()) {
		// std::cout << "Error: Empty input." << std::endl;
		return (false);
	}
	if (errno == EINVAL)  {
		std::cout << "Error: Bad input => " << amount << std::endl;
		return (false);
	}
	num = static_cast<float>(tmp);
	if (num < 0.0){
		std::cout << "Error: Not a positive number." << std::endl;
		return (false);
	}
	if (num > 1000.0) {
		std::cout << "Error: Too large number." << std::endl;
		return (false);
	}
	return (true);	
}

float BitcoinExcange::findRate(std::string const& date) {
	float rate;
	std::map<std::string, float>::iterator it = _database.begin();
	std::map<std::string, float>::iterator ite = _database.end();
	rate = it->second;
	while (it != ite) {
		if (it->first >= date)
			break ;
		rate = it->second;
		++it;
	}
	return (rate);
}
