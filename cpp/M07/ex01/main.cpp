/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:37:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/16 11:11:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	print_char(char& c) {std::cout << c;}
void	print_int(int& i) {std::cout << i;}
void	add_int(int& i) {i++;}

void	to_upper(char& c) 
{
	if (islower(c))
		c -= 32;
}

int	main(void)
{
	int		arri[5] = {0, 1, 2, 3, 4};
	char	arrc[7] = "hello!";

	::iter(arri, 5, print_T);
	std::cout << std::endl;
	::iter<int, size_t>(arri, 5, add_int);
	::iter<int, size_t>(arri, 5, print_T);
	std::cout << std::endl;
	::iter<char, size_t>(arrc, 7, print_T);
	std::cout << std::endl;
	::iter<char, size_t>(arrc, 7, to_upper);
	::iter(arrc, 7, print_T);
	std::cout << std::endl;
	return (0);
}
