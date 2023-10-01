/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:55:24 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 16:41:22 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Constructor test" << std::endl;
	try 
	{	
		Bureaucrat	b("Smith", 141);
		std::cout << b << std::endl;

		Bureaucrat	c;
		std::cout << c << std::endl;
		c = b;
		std::cout << c << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{	
		Bureaucrat	b("Smithons", 1141);
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{	
		Bureaucrat	b("Smithus", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Increment/decrement test" << std::endl;
	try 
	{	
		Bureaucrat	b("Smithus", 3);
		std::cout << b << std::endl;
		b.incGrade();
		std::cout << b << std::endl;
		b.incGrade();
		std::cout << b << std::endl;
		b.incGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{	
		Bureaucrat	b("Smithon", 148);
		std::cout << b << std::endl;
		b.decGrade();
		std::cout << b << std::endl;
		b.decGrade();
		std::cout << b << std::endl;
		b.decGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
