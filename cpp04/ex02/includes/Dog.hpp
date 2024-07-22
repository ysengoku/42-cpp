/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:32 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/22 10:40:39 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

# define DOG_IDEAS "Play!", "I'm hungry.", "I'm sleepy.", "Let's go for a Walk?"

class Dog : public AAnimal
{
	public:
		Dog( void );
		Dog( const Dog& src );
		Dog& operator=( const Dog& rhs );
		~Dog( void );

		void	makeSound( void ) const;
		void	showIdeas( void ) const;
		void	updateIdea( std::string const& idea, unsigned int i  ) const;

	private:
		Brain*	_brain;
};


#endif
