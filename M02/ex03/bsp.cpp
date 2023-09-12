/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:49:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 15:13:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed	det(Point const u, Point const v)
{
	return (u.getX() * v.getX() - u.getY() * v.getX());
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	k1;
	Fixed	k2;

	k1 = (det(point, c) - det(a, c)) / (det(b, c));
	k2 = (det(point, b) - det(a, b)) / (det(b, c));
	if (k1 <= 0 || k2 <= 0 || (k1 + k2) >= 1)
		return (false);
	return (true);
}
