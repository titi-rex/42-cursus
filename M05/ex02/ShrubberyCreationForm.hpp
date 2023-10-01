/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:17:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 22:11:10 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHRUBBERY_CREATION_FORM_H__
# define _SHRUBBERY_CREATION_FORM_H__
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public	:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm(std::string target);

		void	execute(Bureaucrat const & executor) const;
};

#endif
