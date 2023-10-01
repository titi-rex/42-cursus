/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:37:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 18:07:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("unkonw form"), _signed(false), _gradeSign(150), _gradeExecute(150) {};

Form::Form(const Form& src) : _name(src.getName()), _signed(src.getSigned()), _gradeSign(_check_grade(src.getGradeSign())), _gradeExecute(_check_grade(src.getGradeExe())) {};

Form&	Form::operator=(const Form& src) 
{
	if (this == &src)
		return (*this);
	this->~Form();
	new(this) Form(src);
	return (*this);
};

Form::~Form(void) {};

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _signed(false), _gradeSign(_check_grade(gradeSign)), _gradeExecute(_check_grade(gradeExecute)) {};

int	Form::_check_grade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException("Grade too high at construction");
	if (grade > 150)
		throw Form::GradeTooLowException("Grade too low at construction");
	return (grade);
}

void	Form::beSigned(Bureaucrat& B)
{
	if (this->_signed)
		throw Form::signedException("already signed");
	if (B.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException("grade too low");
};

const std::string&	Form::getName(void) const { return (this->_name); };
bool				Form::getSigned(void) const { return (this->_signed); };
int					Form::getGradeSign(void) const { return (this->_gradeSign); };
int					Form::getGradeExe(void) const { return (this->_gradeExecute); };

std::ostream&	operator<<(std::ostream& os, const Form& F)
{
	return (os << "Form " << F.getName() << " required grade : " << F.getGradeSign() << " (signature), " << F.getGradeExe() << " (execution)");
};

