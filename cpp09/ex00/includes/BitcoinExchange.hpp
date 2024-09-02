/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:31:55 by yusengok          #+#    #+#             */
/*   Updated: 2024/09/02 10:26:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <cerrno>
# include <ctime>

# ifndef DATABASE
# 	define DATABASE "./data.csv"
# endif

class BitcoinExcange {
	private:
		std::map<std::string, float> _database;
		char* _inputFileName;
		std::ifstream _ifs;
		std::string _today;

		void setTodaysDate(void);
		bool readDatabase(void);
		bool checkDate(std::string const&);
		bool checkAmount(std::string const&);
		float findRate(std::string const&);
		
		BitcoinExcange(void);
		BitcoinExcange& operator=(BitcoinExcange const& rhs);

	public:
		BitcoinExcange(char* inputFileName);
		BitcoinExcange(BitcoinExcange const& src);
		~BitcoinExcange(void);

		void exchange(void);
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GREY "\e[0;90m"
# define BGCYAN "\033[46m"
# define RESET "\033[0m"

#endif
