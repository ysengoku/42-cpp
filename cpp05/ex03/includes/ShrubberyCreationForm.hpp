/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:51:52 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/29 10:17:44 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const& target );
		ShrubberyCreationForm( ShrubberyCreationForm const& src );
		~ShrubberyCreationForm( void );

        std::string const&    getTarget( void );

		void	execute( Bureaucrat const& executor ) const;

	private:
		const std::string	_target;
        
		ShrubberyCreationForm& operator=( ShrubberyCreationForm const& rhs );
};

# define TREE "\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n"

#endif
