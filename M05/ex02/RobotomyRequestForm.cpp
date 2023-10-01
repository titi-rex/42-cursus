/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:26:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 22:42:30 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", "nobody", 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src) {};

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src) 
{
	if (this == &src)
		return (*this);
	return (*this);
};

RobotomyRequestForm::~RobotomyRequestForm(void) {};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", target, 72, 45) {};


void	RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
	this->checkExe(executor.getGrade());
	
	time_t	t(std::time(NULL));
	
	std::cout << "*robotic drilling noises*" << std::endl;
	if (t % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy has failed" << std::endl;
};
	
