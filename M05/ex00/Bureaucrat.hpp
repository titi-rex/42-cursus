/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:56:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 16:32:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_H__
# define _BUREAUCRAT_H__
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat 
{
	
	private	:
		const std::string	_name;
		int					_grade;
		void	_setGrade(int grade);

	public	:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat&	operator=(const Bureaucrat& src);
		~Bureaucrat(void);

		Bureaucrat(std::string name, int grade);
		Bureaucrat(int grade);
		
		std::string	getName(void) const;
		int		getGrade(void) const;
		
		void	incGrade(void);
		void	decGrade(void);

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
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& B);

#endif
