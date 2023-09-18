/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:50:50 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/18 21:48:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void) : _type("unknow weapon") {std::cout << "Weapon default constructor called" << std::endl;};

Weapon::Weapon(std::string type) : _type(type) {std::cout << "Weapon type constructor called" << std::endl;};

Weapon::~Weapon(void) {std::cout << "Weapon destructor called" << std::endl;};

const std::string&	Weapon::getType(void) const
{
	return(this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
