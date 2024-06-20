/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 00:21:50 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/21 20:50:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point	a(1, 1);
	Point	b(5, 0);
	Point	c(2.5, 5);
	Point	point(3.45, 3);
	
	a.setName("a");
	b.setName("b");
	c.setName("c");
	point.setName("point");

	point.info();
	if (bsp(a, b, c, point) == true)
		std::cout <<  " is inside the triangle !" << std::endl;
	else
		std::cout <<  " is not inside the triangle..." << std::endl;
	std::cout << "formed by " << std::endl;
	a.info();
	b.info();
	c.info();
	return (0);
}
