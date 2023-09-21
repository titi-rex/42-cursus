/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:06:22 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/21 16:24:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _value(0) {std::cout << "Default constructor called" << std::endl;};

Fixed::~Fixed(void) {std::cout << "Destructor called" << std::endl;};

Fixed::Fixed(const Fixed& F) 
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(F.getRawBits());
};

Fixed&	Fixed::operator=(const Fixed& F) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &F)
		return (*this);
	this->setRawBits(F.getRawBits());
	return (*this);
};

int	Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_value);
};

void	Fixed::setRawBits(int const raw) 
{
	this->_value = raw;
};

const int	Fixed::_bit = 8;
