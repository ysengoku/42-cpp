/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:53:29 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/28 09:58:39 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

#include <iostream>
#include <string>
#include <fstream>

class	FileHandler
{
	public:
		/* Constructor & Destructor */
		FileHandler( std::string infileName );
		~FileHandler( void );
	
		/* Member functions */
		bool				openInfile( void );
		bool				openOutfile( void );
		void				closeFiles( void );
		std::ifstream&		getInputFile( void );
		std::ofstream&		getOutputFile( void );
		const std::string	getInfileName( void );
		const std::string	getOutfileName( void );
		
	private:
		std::string		_infileName;
		std::string		_outfileName;
		std::ifstream	_ifs;
		std::ofstream	_ofs;
};

#endif
