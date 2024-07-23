/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:32 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 10:44:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog( void );
		Dog( const Dog& src );
		Dog& operator=( const Dog& rhs );
		~Dog( void );

		void	makeSound( void ) const;
		void	showIdea( unsigned int i ) const;
		void	showAllIdeas( void ) const;
		void	setIdeaToBrain( std::string const& idea, unsigned int i ) const;

	private:
		Brain*	_brain;
};


#endif
