/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 18:10:14 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) 
{
	this->setType("Cat");
	std::cout << "Cat default constructor" << std::endl;
};

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat copy constructor" << std::endl;
};

Cat&	Cat::operator=(const Cat& src) 
{
	if (this == &src)
		return (*this);
	this->Animal::operator=(src);
	return (*this);
};


Cat::~Cat(void) {std::cout << "Cat destructor" << std::endl;};

void	Cat::makeSound(void) const 
{
	std::cout << "Mew mew mew mewwwww" << std::endl;
};
	
