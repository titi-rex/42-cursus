/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:49:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 20:55:26 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	scav1("irina");

	scav1.setAd(15);
	FragTrap	scav2(scav1);

	scav2.setName("Shedorus");
	scav1.attack("the wall");
	scav1.highFiveGuys();
	scav1.beRepaired(15);
	scav1.takeDamage(600);
	scav1.highFiveGuys();
	scav2.highFiveGuys();
	scav2.highFiveGuys();
	scav2.attack("bob");
	return (0);
}
