/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:29 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 10:44:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat( void );
		Cat( const Cat& src );
		Cat& operator=( const Cat& rhs );
		~Cat( void );

		void	makeSound( void ) const;
		void	showIdea( unsigned int i ) const;
		void	showAllIdeas( void ) const;
		void	setIdeaToBrain( std::string const& idea, unsigned int i ) const;

	private:
		Brain*	_brain;
};

#endif
