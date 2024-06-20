/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:25:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 22:45:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ROBOTOMY_REQUEST_FORM_H__
# define _ROBOTOMY_REQUEST_FORM_H__
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public	:

		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(std::string target);

		void	execute(Bureaucrat const & executor) const;
};

#endif
