/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:27 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 21:25:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("animal") {std::cout << "Animal default constructor" << std::endl;};

Animal::Animal(const Animal& src) 
{
	this->setType(src.getType());
	std::cout << "Animal copy constructor" << std::endl;
};

Animal&	Animal::operator=(const Animal& src) 
{
	if (this == &src)
		return (*this);
	this->setType(src.getType());
	return (*this);
};

Animal::~Animal(void) {std::cout << "Animal destructor" << std::endl;};

std::string	Animal::getType(void) const { return (this->_type); };
void		Animal::setType(std::string type) { this->_type = type; };

