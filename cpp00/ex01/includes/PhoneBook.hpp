/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:07:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/16 15:40:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook {

	public:
		PhoneBook( void );
		~PhoneBook( void );

		void	addContact( void );
		void	displayContact( void );

	private:
		Contact _contacts[8];
		int		_count;

		void	_replaceContact( int *i );
		void	_displayContactTable( void );
		void	_displayContactDetail( int index );
};

# define RESET		"\033[0m"
# define WHITE 		"\033[1;37m"
# define BLACK		"\033[1;30m"
# define BLUE		"\033[1;34m"
# define YELLOW		"\033[1;33m"
# define GREEN		"\033[1;32m"
# define RED		"\033[1;31m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define BGCYAN		"\033[46m"
# define BGWHITE	"\033[47m"

#endif