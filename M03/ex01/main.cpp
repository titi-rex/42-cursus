/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:49:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 17:06:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scap;

	scap.setAd(1);
	ScavTrap	scapou(scap);

	std::cout << scap.getAd() << std::endl;
	std::cout << scapou.getAd() << std::endl;
	return (0);
}
