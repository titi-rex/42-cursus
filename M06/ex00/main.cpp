/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:17:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/03 15:01:55 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char** arg)
{
	ScalarConverter	converter;

	if (ac != 2)
	{
		std::cerr << "Wrong number of arg" << std::endl;
		return (1);
	}
	
	std::string		input(arg[1]);
	// std::cout << arg[1] << std::endl;
	// std::cout << input << std::endl;
	// std::cout << int(arg[1][0]) << std::endl;
	// std::cout << int(input[0]) << std::endl;

	converter.convert(input);
	return (0);	
}
