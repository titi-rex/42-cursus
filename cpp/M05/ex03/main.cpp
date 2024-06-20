/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:55:24 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/14 18:47:13 by tlegrand         ###   ########.fr       */
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
	AForm*	f1;
	AForm*	f2;
	AForm*	f3;
	
	try 
	{
		f1 = pj.makeForm("shrubbery creation", "here");
		f2 = pj.makeForm("robotomy request", "Julien");
		f3 = pj.makeForm("presidential pardon", "Sasha");
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
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}


	delete f1;
	delete f2;
	delete f3;
	
	return (0);
}
