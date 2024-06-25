/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:58:16 by yusengok          #+#    #+#             */
/*   Updated: 2024/06/25 15:49:08 by yusengok         ###   ########.fr       */
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
		Zombie( void );
		/* Destractor */
		~Zombie( void );
	
		/* Member functions */

	
	private:
		std::string	_name;

		/* Member functions */
		void	announce( void );
	
};

#endif
