/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/10 11:33:36 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) 
{
	this->setType("Cat");
	this->_brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
};

Cat::Cat(const Cat& src) : Animal(src)
{
	this->_brain = new Brain(src.getBrain());
	std::cout << "Cat copy constructor" << std::endl;
};

Cat&	Cat::operator=(const Cat& src) 
{
	if (this == &src)
		return (*this);
	this->Animal::operator=(src);
	delete this->_brain;
	this->_brain = new Brain(src.getBrain());
	return (*this);
};

Cat::~Cat(void) 
{
	std::cout << "Cat destructor" << std::endl;
	delete	this->_brain;
};

void	Cat::makeSound(void) const 
{
	std::cout << "Mew mew mew mewwwww" << std::endl;
};
	
Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
};
