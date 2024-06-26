/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:07:16 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 15:13:50 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie
{	
	public:
		/* Constructor */
		Zombie( void );
		Zombie( std::string _name );
		/* Destructor */
		~Zombie( void );
	
		/* Member functions */
		void	announce( void );
		static Zombie*	zombieHorde( int N, std::string name );
	
	private:
		std::string	_name;
};

#endif
