/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:03:05 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/20 15:26:22 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char** arg)
{
	Harl		harl;
	std::string	level;
	
	if (ac != 2)
		return (0);
	level = arg[1];
	harl.filter(level);
	return (0);
}