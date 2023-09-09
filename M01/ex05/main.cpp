/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:03:05 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/10 00:05:39 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Harl.hpp"

int	main(int ac, char** arg)
{
	Harl		harl;
	std::string	level;
	
	if (ac != 2)
		return (0);
	level = arg[1];
	harl.complain(level);
	return (0);
}