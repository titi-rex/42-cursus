/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:25:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 22:46:04 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRESIDENTIAL_PARDON_FORM_H__
# define _PRESIDENTIAL_PARDON_FORM_H__
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public	:

		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm(void);

		PresidentialPardonForm(std::string target);

		void	execute(Bureaucrat const & executor) const;
};

#endif
