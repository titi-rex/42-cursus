/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:32:10 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/21 16:08:36 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0), _name("nameless") {};

Point::Point(const Point& cpy) : _x(cpy.getX()), _y(cpy.getY()), _name(cpy.getName()) {};

Point&	Point::operator=(const Point& cpy) 
{
	if (this == &cpy)
		return (*this);

	return (*this);
};

Point::~Point(void) {};

Point::Point(const float x, const float y) : _x(x), _y(y), _name("nameless") {};
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y), _name("nameless") {};

Fixed const	Point::getX(void) const { return (this->_x); };

Fixed const	Point::getY(void) const { return (this->_y); };

std::string	Point::getName(void) const {return(this->_name);};

void	Point::setName(std::string name) {this->_name = name;};

void	Point::info(void) const
{
	std::cout << "Point " << this->getName() << " x:" << this->getX() << " y:" << this->getY() << std::endl;
}

Point	Point::operator-(const Point& F) const
{
	Fixed	tmpX;
	Fixed	tmpY;

	tmpX = this->getX() - F.getX();
	tmpY = this->getY() - F.getY();

	Point	res(tmpX, tmpY);
	return (res);
};

