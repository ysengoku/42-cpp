/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:22:16 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 12:16:46 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "Materia.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( Cure const& src );
		Cure& operator=( Cure const& rhs );
		~Cure( void );

		void	use( ICharacter& target );
};

#endif
