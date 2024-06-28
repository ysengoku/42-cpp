/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:52:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/27 16:47:11 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include "FileHandler.hpp"
# include "StringReplacer.hpp"

class Replacer
{
	public:
		/* Constructor & Destructor */
		Replacer( std::string const filename, std::string const s1, std::string const s2);
		~Replacer( void );

		/* Member functions */
		int	replaceText( void );
		
	private:
		const std::string	_infileName;
		const std::string	_searchedStr;
		const std::string	_replacingStr;
		bool				_replaced;
		FileHandler			_fileHandler;
		StringReplacer		_stringReplacer;

		/* Member functions */
		void	replaceStrings( void );
		void	printStatus( void );
};

#endif