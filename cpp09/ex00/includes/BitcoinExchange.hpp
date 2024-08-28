/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:31:55 by yusengok          #+#    #+#             */
/*   Updated: 2024/08/28 12:35:04 by yusengok         ###   ########.fr       */
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
# include <climits>
# include <limits>
# include <cerrno>

# define DATABASE "../data.csv"
# define FLOAT_MAX std::numeric_limits<float>::max()

class BitcoinExcange {
	private:
		std::map<std::string, float> _database;
		std::ifstream _ifs;

		float strToFloat(std::string const& str);

	public:
		BitcoinExcange(void);
		BitcoinExcange(BitcoinExcange const& src);
		BitcoinExcange& operator=(BitcoinExcange const& rhs);
		~BitcoinExcange(void);

		void readDatabase(void);
		void openInputFile(char* filename);

		class FileOpenErrorException : std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InvalidValueException : std::exception {
			public:
				virtual const char* what() const throw();
		};
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
