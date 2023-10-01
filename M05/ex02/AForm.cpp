/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:37:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 21:56:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("unknow form"), _target("nobody"), _gradeSign(150), _gradeExecute(150), _signed(false) {};

AForm::AForm(const AForm& src) : _name(src.getName()), _target(src.getTarget()), _gradeSign(_checkGradeCons(src.getGradeSign())), _gradeExecute(_checkGradeCons(src.getGradeExe())), _signed(src.getSigned()) {};

AForm&	AForm::operator=(const AForm& src) 
{
	if (this == &src)
		return (*this);
	return (*this);
};

AForm::~AForm(void) {};

AForm::AForm(std::string name, std::string target, int gradeSign, int gradeExecute) : _name(name), _target(target), _gradeSign(_checkGradeCons(gradeSign)), _gradeExecute(_checkGradeCons(gradeExecute)), _signed(false) {};

int	AForm::_checkGradeCons(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException("Grade too high at construction");
	if (grade > 150)
		throw AForm::GradeTooLowException("Grade too low at construction");
	return (grade);
}

const std::string&	AForm::getName(void) const { return (this->_name); };
const std::string&	AForm::getTarget(void) const { return (this->_target); };
bool				AForm::getSigned(void) const { return (this->_signed); };
int					AForm::getGradeSign(void) const { return (this->_gradeSign); };
int					AForm::getGradeExe(void) const { return (this->_gradeExecute); };

void	AForm::beSigned(Bureaucrat& B)
{
	if (this->_signed)
		throw AForm::signedException("already signed");
	if (B.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException("grade too low");
};

void	AForm::checkExe(int grade) const
{
	if (this->_signed == false)
		throw AForm::signedException("form not signed");
	if (grade > this->_gradeExecute)
		throw AForm::GradeTooLowException("grade too low");
};


std::ostream&	operator<<(std::ostream& os, const AForm& F)
{
	return (os << "Form " << F.getName() << " required grade : " << F.getGradeSign() << " (signature), " << F.getGradeExe() << " (execution)");
};

