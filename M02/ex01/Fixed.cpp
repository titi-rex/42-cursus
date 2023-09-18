/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:06:22 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/18 22:06:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_point = 8;

std::ostream&	operator<<(std::ostream& os, const Fixed& F)
{
	os << F.toFloat();
	return (os);
};

Fixed::Fixed(void) : _rawbits(0) {std::cout << "Default constructor called" << std::endl;};

Fixed::Fixed(const Fixed& F) 
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(F.getRawBits());
};

Fixed::Fixed(const int value) 
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->_point);
};

Fixed::Fixed(const float value) 
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(roundf(value * (1 << this->_point))));
};

Fixed::~Fixed(void) {std::cout << "Destructor called" << std::endl;};

Fixed&	Fixed::operator=(const Fixed& F) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &F)
		return (*this);
	this->setRawBits(F.getRawBits());
	return (*this);
};

int	Fixed::getRawBits(void) const {return(this->_rawbits);};

void	Fixed::setRawBits(int const raw) {this->_rawbits = raw;};

int	Fixed::toInt(void) const
{
	return (this->_rawbits >> this->_point);
};

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_rawbits) / (1 << this->_point));
};
