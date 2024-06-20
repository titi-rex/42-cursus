/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:03:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/20 15:22:54 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {std::cout << "HumanA constructor called" << std::endl;};

HumanA::~HumanA(void) {std::cout << "HumanA destructor called" << std::endl;};

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attack with their " << this->_weapon.getType() << std::endl;
};

