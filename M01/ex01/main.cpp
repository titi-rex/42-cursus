/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:57:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/20 16:33:26 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

typedef Zombie* ZombiePtr;

void	announceHorde(int const N, ZombiePtr const horde)
{
	for (int i = 0; i < N; ++i)
		horde[i].announce();
}

int	main(void)
{
	ZombiePtr	horde;
	
	horde = zombieHorde(3, "Lily");
	if (horde == NULL)
		return (1);
	announceHorde(3, horde);
	delete[] horde;
	return (0);
}
