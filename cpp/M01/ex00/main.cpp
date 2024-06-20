/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:57:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/19 17:39:22 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	Zombie	*p_zombie1;
	Zombie	*p_zombie2;
	
	p_zombie1 = newZombie("Fred");
	p_zombie2 = newZombie("Judith");
	p_zombie1->announce();
	p_zombie2->announce();
	randomChump("Marc");
	randomChump("Clara");
	delete p_zombie1;
	delete p_zombie2;
	return (0);
}
