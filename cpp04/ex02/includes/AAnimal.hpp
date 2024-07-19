/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:07:22 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 10:43:43 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	AAnimal
{
	public:
		AAnimal( void );
		AAnimal( const std::string type );
		AAnimal( const AAnimal& src );
		virtual AAnimal& operator=( const AAnimal& rhs);
		virtual ~AAnimal( void );

		std::string const&	getType( void ) const;

		virtual void	makeSound( void ) const = 0;
		virtual void	showIdeas( void ) const = 0;
		virtual void	updateIdea( std::string const& idea, unsigned int i ) const = 0;
	 	
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
