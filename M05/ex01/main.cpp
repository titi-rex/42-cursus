/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:55:24 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 18:08:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Constructor test" << std::endl;
	try 
	{	
		Form	f("AB-41", 141, 5);
		std::cout << f << std::endl;

		Form	e;
		std::cout << e << std::endl;
		e = f;
		std::cout << e << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{	
		Form	f("AB-43", 159, 5);
		std::cout << f << std::endl;

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{	
		Form	f("AB-49", -5, 5);
		std::cout << f << std::endl;

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b1("Smith", 15);
		Bureaucrat	b2("Smithus", 147);

		Form	f1("AC-12", 97, 13);
		Form	f2("AC-15", 15, 1);

		b1.signForm(f1);
		b2.signForm(f1);
		b2.signForm(f2);
		b2.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
