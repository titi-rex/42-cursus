/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:50:50 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/21 19:10:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(void) {};

Weapon::Weapon(std::string type) : _type(type) {};

Weapon::~Weapon(void) {};

const std::string&	Weapon::getType(void) const
{
	return(this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
