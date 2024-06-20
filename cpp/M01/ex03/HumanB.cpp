/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:17:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/18 21:45:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {std::cout << "HumanB constructor called" << std::endl;};

HumanB::~HumanB(void) {std::cout << "HumanB destructor called" << std::endl;};

void	HumanB::setWeapon(Weapon* weapon)
{
	this->_weapon = weapon;
};


void	HumanB::attack(void) const
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have any weapon..." << std::endl;
};