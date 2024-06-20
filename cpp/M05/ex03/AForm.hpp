/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:37:10 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/13 20:40:22 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AFORM_H__
# define _AFORM_H__
# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	private	:
		const std::string	_name;
		const std::string	_target;
		const int			_gradeSign;
		const int			_gradeExecute;
		bool				_signed;
		int					_checkGradeCons(int grade);

	public	:
		AForm(void);
		AForm(const AForm& src);
		AForm&	operator=(const AForm& src);
		virtual ~AForm(void);

		AForm(std::string name, std::string target, int gradeSign, int gradeExecute);

		const std::string&	getName(void) const;
		const std::string&	getTarget(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExe(void) const;

		void			beSigned(Bureaucrat& B);
		void			checkExe(int grade) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::invalid_argument
		{
			public	:
				GradeTooHighException(std::string str) : invalid_argument(str) {};
		};
		class GradeTooLowException : public std::invalid_argument
		{
			public	:
				GradeTooLowException(std::string str) : invalid_argument(str) {};
		};
		class signedException : public std::runtime_error
		{
			public	:
				signedException(std::string str) : runtime_error(str) {};
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& F);

#endif
