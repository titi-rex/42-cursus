/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:48:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/02 21:20:26 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERN_H__
# define _INTERN_H__
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern 
{
	private	:
		typedef AForm* (Intern::*_createPtr)(std::string) const;
		AForm*	_NewShrubberyCreation(std::string target) const;
		AForm*	_NewRobotomyRequest(std::string target) const;
		AForm*	_NewPresidentialPardon(std::string target) const;
	
	public	:
		Intern(void);
		Intern(const Intern& src);
		Intern&	operator=(const Intern& src);
		~Intern(void);

		AForm*	makeForm(std::string form, std::string target) const;
};

#endif
