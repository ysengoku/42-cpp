/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:22:19 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 12:17:19 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "Materia.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( Ice const& src );
		Ice& operator=( Ice const& rhs );
		~Ice( void );

		void	use( ICharacter& target );
};

#endif
