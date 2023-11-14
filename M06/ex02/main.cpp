/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:07:49 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/14 19:06:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base*	generate(void)
{
	int	i = std::rand() % 3;

	switch (i)
	{
		case 0 :
			return (new A);
		case 1 :
			return (new B);
		case 2 :
			return (new C);
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Objet is class A!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Objet is class B!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Objet is class C!" << std::endl;
	else
		std::cout << "Can't identify object.." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Objet is class A!" << std::endl;
		(void)a;
		return ;
	}
	catch(std::exception & e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Objet is class B!" << std::endl;
		(void)b;
		return ;
	}
	catch(std::exception & e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Objet is class C!" << std::endl;
		(void)c;
		return ;
	}
	catch(std::exception & e) {}
	std::cout << "Can't identify object.." << std::endl;
}

int	main(void)
{
	std::srand(std::time(NULL));
	Base*	ptr;
	Base	p;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	ptr = &p;
	identify(ptr);
	identify(p);
	return (0);
}
