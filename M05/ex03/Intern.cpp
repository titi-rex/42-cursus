/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:47:58 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/02 21:24:46 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {};

Intern::Intern(const Intern& src) {(void)(src);};

Intern&	Intern::operator=(const Intern& src) 
{
	if (this == &src)
		return (*this);
	return (*this);
};

Intern::~Intern(void) {};

AForm*	Intern::_NewShrubberyCreation(std::string target) const {return (new ShrubberyCreationForm(target));};
AForm*	Intern::_NewRobotomyRequest(std::string target) const {return (new RobotomyRequestForm(target));};
AForm*	Intern::_NewPresidentialPardon(std::string target) const {return (new PresidentialPardonForm(target));};

AForm*	Intern::makeForm(const std::string form, std::string target) const 
{
	std::string	listForm[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	_createPtr	f[3] = {&Intern::_NewShrubberyCreation, &Intern::_NewRobotomyRequest, &Intern::_NewPresidentialPardon};
	
	for (int i=0; i<3; ++i)
	{
		if (listForm[i].compare(form) == 0)
			return ((this->*f[i])(target));
	}
	return (NULL);
};
