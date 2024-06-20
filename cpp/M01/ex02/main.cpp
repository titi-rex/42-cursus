/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:27:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/21 18:39:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory addresse of string " << &string << std::endl; 
	std::cout << "Memory addresse held by stringPTR " << stringPTR << std::endl; 
	std::cout << "Memory addresse held by stringREF " << &stringREF << std::endl; 
	std::cout << "Value of string " << string << std::endl; 
	std::cout << "Value pointed by stringPTR " << *stringPTR << std::endl; 
	std::cout << "Value pointed by stringREF " << stringREF << std::endl;
	return (0);
}
