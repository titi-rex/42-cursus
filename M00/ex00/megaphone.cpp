/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:50:48 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/15 12:50:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int c, char **arg)
{
	std::string	str;
	
	if (c == 1)
	{	
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE. *" << std::endl;
		return (0);
	}
	for(int i = 1; i < c; ++i)
	{
		str += arg[i];
		if (i < c - 1)
			str += ' ';
	}
	for (int i = 0; i < str.length(); ++i)
		str.at(i) = static_cast<char>(std::toupper(str.at(i)));
	std::cout << str << std::endl;
	return (0);
}
