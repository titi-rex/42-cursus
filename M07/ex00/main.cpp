/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:09:55 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/15 21:13:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Template.hpp"

int	main(void)
{
	{
		int	a = 5;
		int	b = 0;
		
		std::cout << "a is " << a << ", b is " << b << std::endl;
		std::cout << "swap" << std::endl;
		::swap(a, b);
		std::cout << "a is " << a << ", b is " << b << std::endl;
		std::cout << "min is " << ::min(a, b) << std::endl;
		std::cout << "max is " << ::max(a, b) << std::endl;
	}
	{
		float	a = 5.9;
		float	b = 0.1;
		
		std::cout << "a is " << a << ", b is " << b << std::endl;
		std::cout << "swap" << std::endl;
		::swap(a, b);
		std::cout << "a is " << a << ", b is " << b << std::endl;
		std::cout << "min is " << ::min(a, b) << std::endl;
		std::cout << "max is " << ::max(a, b) << std::endl;
	}
	{
		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	return (0);
}
