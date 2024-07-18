/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:29 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/18 14:54:07 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# define CAT_IDEAS "Food dish is empty!", "Nap time?", "This is my place.", "Who is he?"

class Cat : public Animal
{
	public:
		Cat( void );
		Cat( const Cat& src );
		Cat& operator=( const Cat& rhs );
		~Cat( void );

		void	makeSound( void ) const;
		void	voiceIdea( void ) const;
		void	replaceIdea( const std::string idea, unsigned int i  ) const;

	private:
		Brain*	_brain;
};

#endif
