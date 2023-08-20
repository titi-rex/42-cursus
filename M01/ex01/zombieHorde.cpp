/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:36:02 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/20 23:50:55 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	horde = new Zombie[N];
	for (std::size_t i{0}; i < N; ++i)
		new (&horde[i]) Zombie(name);
	return (horde);
}
