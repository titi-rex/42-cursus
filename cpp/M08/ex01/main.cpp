/*, ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:56:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/25 12:21:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int	main(void)
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		int arr[50] = {13, 9, 55, 96, 48, 44, 80, 84, 85, 59, 26, 1, 46, 86, 16, 94, 82, 56, 97, 73, 2, 18, 54, 67, 100, 75, 90, 77, 31, 25, 47, 39, 37, 95, 20, 35, 24, 22, 89, 92, 42, 23, 4, 29, 49, 52, 58, 87, 28, 78};
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

		Span p(50);
		p.addRange(vec.begin(), vec.end());
		std::cout << p.shortestSpan() << std::endl;
		std::cout << p.longestSpan() << std::endl;
	}
	
	return (0);
}
