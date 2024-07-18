/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:32 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/18 14:49:20 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "../includes/Animal.hpp"
# include "Brain.hpp"

# define DOG_IDEAS "Play!", "I'm hungry.", "I'm sleepy.", "Let's go for a Walk?"

class Dog : public Animal
{
	public:
		Dog( void );
		Dog( const Dog& src );
		Dog& operator=( const Dog& rhs );
		~Dog( void );

		void	makeSound( void ) const;
		void	voiceIdea( void ) const;
		void	replaceIdea( const std::string idea, unsigned int i  ) const;

	private:
		Brain*	_brain;
};


#endif
