/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:37 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/23 10:16:51 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat( void );
		WrongCat( const WrongCat& src );
		WrongCat& operator=( const WrongCat& rhs );
		~WrongCat( void );
		
		void	makeSound( void ) const;
		void	showAllIdeas( void ) const;
		void	updateIdea( std::string const& idea, unsigned int i  ) const;

	private:
		Brain*	_brain;
};

#endif
