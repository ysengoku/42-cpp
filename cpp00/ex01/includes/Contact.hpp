/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:18 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/16 15:41:28 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class	Contact
{	
	public:
		Contact ( void );
		~Contact ( void );

		void		setFirstName( void );
		void		setLastName( void );
		void		setNickname( void );
		void		setPhone( void );
		void		setDarkestSecret( void );
		std::string getFirstName( void );
		std::string	getLastName( void );
		std::string	getNickname( void );
		std::string	getPhone( void );
		std::string	getSecret( void );

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;

		std::string	_getInput( std::string prompt );
		bool		_isNum( std::string input );
};

# define RESET		"\033[0m"
# define GREEN		"\033[1;32m"
# define RED		"\033[1;31m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"

#endif