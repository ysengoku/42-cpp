/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:07:31 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/17 14:36:53 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain( void );
		Brain( const Brain& src );
		Brain& operator=( const Brain& rhs );
		~Brain( void );

		std::string const&	getIdea();
		void				setIdea( const std::string& idea );

	private:
		std::string	_ideas[100];
};

# define RED "\033[31m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BLACKI "\e[0;90m"
# define RESET "\033[0m"

#endif

// https://zenn.dev/rt3mis10/articles/2d9f5e8bcc06a7