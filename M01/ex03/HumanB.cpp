/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:17:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/21 19:37:09 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {};

HumanB::~HumanB(void) {};

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
};


void	HumanB::attack(void) const
{
	std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
};