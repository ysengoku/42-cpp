/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:15:16 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/19 12:20:58 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const& src );
		MateriaSource& operator=( MateriaSource const& rhs );
		~MateriaSource( void );

		void		learnMateria( AMateria* src );
		AMateria*	createMateria( std::string const & type );

	private:
		AMateria*	_materias[4];
};

#endif
