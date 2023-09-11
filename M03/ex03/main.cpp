/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:49:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 21:45:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	bot1("irina");
	DiamondTrap	bot2(bot1);

	bot1.whoAmI();
	bot1.attack("bob");
	bot1.guardGate();
	bot1.guardGate();
	// bot2.setName("Shedorus");
	// bot1.attack("the wall");
	// bot1.highFiveGuys();
	// bot1.beRepaired(15);
	// bot1.takeDamage(600);
	// bot1.highFiveGuys();
	// bot2.highFiveGuys();
	// bot2.highFiveGuys();
	// bot2.attack("bob");
	return (0);
}
