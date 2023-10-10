/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:29:52 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 22:32:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardon", "nobody", 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src) {};

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src) 
{
	if (this == &src)
		return (*this);
	return (*this);
};

PresidentialPardonForm::~PresidentialPardonForm(void) {};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", target, 25, 5) {};


void	PresidentialPardonForm::execute(Bureaucrat const & executor) const 
{
	this->checkExe(executor.getGrade());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};
	