/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:07:49 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/05 22:41:59 by tlegrand         ###   ########.fr       */
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

void	identify(Base& r)
{
	try
	{
		A& a = dynamic_cast<A&>(r);
		std::cout << "Objet is class A!" << std::endl;
		(void)a;
		return ;
	}
	catch(...) {}
	try
	{
		B& b = dynamic_cast<B&>(r);
		std::cout << "Objet is class B!" << std::endl;
		(void)b;
		return ;
	}
	catch(...) {}
	try
	{
		C& c = dynamic_cast<C&>(r);
		std::cout << "Objet is class C!" << std::endl;
		(void)c;
		return ;
	}
	catch(...) {}
	std::cout << "Can't identify object.." << std::endl;
}

int	main(void)
{
	std::srand(std::time(NULL));
	Base*	ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}
