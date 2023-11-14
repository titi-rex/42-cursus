/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:17:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/14 18:55:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char** arg)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arg" << std::endl;
		return (1);
	}
	ScalarConverter::convert(arg[1]);
	return (0);	
}
