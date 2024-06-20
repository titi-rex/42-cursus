/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:57:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 13:08:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {std::cout << "WrongAnimal default constructor" << std::endl;};

WrongAnimal::WrongAnimal(const WrongAnimal& src) 
{
	this->setType(src.getType());
	std::cout << "WrongAnimal copy constructor" << std::endl;
};

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src) 
{
	if (this == &src)
		return (*this);
	this->setType(src.getType());
	return (*this);
};

WrongAnimal::~WrongAnimal(void) {std::cout << "WrongAnimal destructor" << std::endl;};

std::string	WrongAnimal::getType(void) const { return (this->_type); };
void	WrongAnimal::setType(std::string type) { this->_type = type; };


void	WrongAnimal::makeSound(void) const {std::cout << "Robotic noise" <<std::endl;};
	
