/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:55:24 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/02 21:28:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main(void)
{
	std::cout << "Constructor test" << std::endl;

	Bureaucrat	b1("Smith", 15);
	Bureaucrat	b2("Smithus", 147);
	Bureaucrat	b3("Smithod", 1);
	Intern		pj;

	AForm*	f1 = pj.makeForm("shrubbery creation", "here");
	AForm*	f2 = pj.makeForm("robotomy request", "Julien");
	AForm*	f3 = pj.makeForm("presidential pardon", "Sasha");
	
	try 
	{
		b1.executeForm(*f1);
		b1.signForm(*f1);
		b2.executeForm(*f1);
		b1.executeForm(*f1);
		b2.executeForm(*f2);
		b1.signForm(*f2);
		b1.executeForm(*f2);
		b1.signForm(*f3);
		b1.executeForm(*f3);
		b3.executeForm(*f3);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
