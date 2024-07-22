/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:40:55 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/22 13:42:30 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria( void );
		AMateria( std::string const& type );
		AMateria( AMateria const& src );
		AMateria& operator=( AMateria const& rhs );
		virtual ~AMateria( void );

		std::string const& getType( void ) const;

		virtual AMateria* clone() const = 0;
		virtual void use( ICharacter& target );
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE  "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BLACKI "\e[0;90m"
# define RESET "\033[0m"

#endif
