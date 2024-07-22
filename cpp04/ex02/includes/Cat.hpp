/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:29 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/22 10:40:31 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

# define CAT_IDEAS "Food dish is empty!", "Nap time?", "This is my place.", "Who is he?"

class Cat : public AAnimal
{
	public:
		Cat( void );
		Cat( const Cat& src );
		Cat& operator=( const Cat& rhs );
		~Cat( void );

		void	makeSound( void ) const;
		void	showIdeas( void ) const;
		void	updateIdea( std::string const& idea, unsigned int i ) const;

	private:
		Brain*	_brain;
};

#endif
