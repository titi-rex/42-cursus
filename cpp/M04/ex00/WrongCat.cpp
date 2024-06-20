/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 19:02:36 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) 
{
	this->setType("WrongCat");
	std::cout << "WrongCat default constructor" << std::endl;
};

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor" << std::endl;
};

WrongCat&	WrongCat::operator=(const WrongCat& src) 
{
	if (this == &src)
		return (*this);
	this->WrongAnimal::operator=(src);
	return (*this);
};


WrongCat::~WrongCat(void) {std::cout << "WrongCat destructor" << std::endl;};

void	WrongCat::makeSound(void) const 
{
	std::cout << "Mew mew mew mewwwww" << std::endl;
};
	
