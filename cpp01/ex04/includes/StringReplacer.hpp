/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:41:08 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/10 11:23:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGREPLACER_HPP
# define STRINGREPLACER_HPP

# include <iostream>
# include <string>

class StringReplacer
{
	public:
		/* Constructor & Destructor */
		StringReplacer( std::string searchedStr, std::string replacingStr );
		~StringReplacer( void );

		/* Member functions */
		// bool	replaceString( std::string& line );
		void	replaceString( std::string& line );

	private:
		const std::string	_searchedStr;
		const std::string	_replacingStr;
		const size_t		_searchedStrLength;
};

# endif
