/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:58:16 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/26 14:01:49 by yusengok         ###   ########.fr       */
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
		/* Constractor */
		Zombie( std::string _name );
		/* Destructor */
		~Zombie( void );
	
		/* Member functions */
		void			announce( void );
		static Zombie*	newZombie( std::string name );
		static void		randomChump( std::string name );
	
	private:
		std::string	_name;
};

#endif
