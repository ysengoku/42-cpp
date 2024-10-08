/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:18 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/22 14:50:07 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class	Contact {
	
public:
	/* Constructor */
	Contact ( void );
	/* Destructor */
	~Contact ( void );

	/* Setters */	
	void		setFirstName( void );
	void		setLastName( void );
	void		setNickname( void );
	void		setPhone( void );
	void		setDarkestSecret( void );

	/* Getters */
	std::string getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;
	std::string	getPhone( void ) const;
	std::string	getSecret( void ) const;

private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;

	/* Member functions */
	std::string	_getInput( std::string prompt );	
	bool		_isNum( std::string input ) const;
	bool		_isValidChar( std::string input ) const;
};

# define RESET		"\033[0m"
# define WHITE 		"\033[1;37m"
# define BLACK		"\033[1;30m"
# define YELLOW		"\033[1;33m"
# define GREEN		"\033[1;32m"
# define RED		"\033[1;31m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define BGWHITE	"\033[47m"

#endif
