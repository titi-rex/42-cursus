/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:54:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/27 12:32:43 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int	main(void)
{
	ClapTrap	r1("richaslyson");
	ClapTrap	r2(r1);
	ClapTrap	r3;
	
	r1.setAd(3);
	r3.setName("loulou");
	r3.setAd(13);

	r2.setName("bob");
	r1.attack("bob");
	r2.takeDamage(r1.getAd());
	r2.beRepaired(4);
	r3.attack("rychaslyson");
	r1.takeDamage(r3.getAd());
	r1.attack("loulou");
	r2.beRepaired(0);
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
	r2.attack("boby");
};