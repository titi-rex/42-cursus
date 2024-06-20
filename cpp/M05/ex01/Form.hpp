/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:37:10 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 21:09:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORM_H__
# define _FORM_H__
# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private	:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;
		int					_checkGradeCons(int grade);

	public	:
		Form(void);
		Form(const Form& src);
		Form&	operator=(const Form& src);
		~Form(void);

		Form(std::string name, int gradeSign, int gradeExecute);

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExe(void) const;

		void	beSigned(Bureaucrat& B);

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

std::ostream&	operator<<(std::ostream& os, const Form& F);

#endif
