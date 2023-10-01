/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:56:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 17:44:43 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("nameless"), _grade(150) {};

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName())
{
	this->_setGrade(src.getGrade());
};

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src) 
{
	if (this == &src)
		return (*this);
	this->~Bureaucrat();
	new(this) Bureaucrat(src);
	return (*this);
};

Bureaucrat::~Bureaucrat(void) {};

Bureaucrat::Bureaucrat(std::string name = "nameless", int grade = 150) : _name(name) {this->_setGrade(grade);};

Bureaucrat::Bureaucrat(int grade) : _name("poor smith") {this->_setGrade(grade);};

const std::string&	Bureaucrat::getName(void) const { return (this->_name); };
int					Bureaucrat::getGrade(void) const { return (this->_grade); };

void	Bureaucrat::_setGrade(int grade) 
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high");
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade too low");
	this->_grade = grade;
};

void	Bureaucrat::incGrade(void) {this->_setGrade(this->getGrade() - 1);};
void	Bureaucrat::decGrade(void) {this->_setGrade(this->getGrade() + 1);};

void	Bureaucrat::signForm(Form& F)
{
	if (F.getSigned() == true)
		std::cout << this->_name << " signed " << F.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << F.getName() << " because grade too low" << std::endl;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& B)
{
	return (os << B.getName() << ", bureaucrat grade " << B.getGrade());
};

