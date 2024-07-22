/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:07:22 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/17 14:21:41 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	public:
		Animal( void );
		Animal( const std::string type );
		Animal( const Animal& src );
		Animal& operator=( const Animal& rhs);
		virtual ~Animal( void );

		std::string const&	getType( void ) const;

		virtual void	makeSound( void ) const;
	 	
	protected:
		std::string	_type;
};

# define RED "\033[31m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BLACKI "\e[0;90m"
# define RESET "\033[0m"

#endif