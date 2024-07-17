/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:10:37 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/17 13:00:50 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat( void );
		WrongCat( const WrongCat& src );
		WrongCat& operator=( const WrongCat& rhs );
		~WrongCat( void );
		
		virtual void	makeSound( void ) const;
};

#endif
