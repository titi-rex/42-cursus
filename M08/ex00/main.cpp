/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:56:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/07 13:26:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main(void)
{
	int	base[10] = {25, 48, 1, 96, 51, 2, 23, 78, 741, 0};
	
	std::vector<int>	v(base, base + sizeof(base) / sizeof(int));
	std::list<int>		l(base, base + sizeof(base) / sizeof(int));


	
	
	int	val = 96;
	try
	{
		easyfind(v, val);
		std::cout << val << " found !" << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(l, val);
		std::cout << val << " found !" << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
}
