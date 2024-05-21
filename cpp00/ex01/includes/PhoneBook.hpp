/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:07:59 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/21 08:09:09 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <iomanip>
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

	void	_printMenu( void ) const;
	int		_replaceContact( void );
	void	_displayContactTable( void );
	void	_printTableElement( std::string element );
	void	_displayContactDetail( void );
};

#endif