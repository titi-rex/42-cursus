/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:17:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/09 23:46:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {std::cout << "HumanB constructor called" << std::endl;};

HumanB::~HumanB(void) {std::cout << "HumanB desstructor called" << std::endl;};

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
};


void	HumanB::attack(void) const
{
	std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
};