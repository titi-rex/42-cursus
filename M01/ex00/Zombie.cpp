/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:03:59 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 22:18:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : _name("") {std::cout << "Anonimous zombie rise from the dead!" << std::endl;};

Zombie::Zombie(std::string name) : _name(name) {std::cout << this->_name << ": Rise from the dead!" << std::endl;};

Zombie::~Zombie(void) {std::cout << this->_name << ": Died again.." << std::endl;};

void	Zombie::announce(void) {std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;};
