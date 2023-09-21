/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:49:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/21 20:51:14 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed	det(Point const u, Point const v)
{
	return ((u.getX() * v.getY()) - (u.getY() * v.getX()));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	bN(b - a);
	Point	cN(c - a);

	Fixed	k1;
	Fixed	k2;
	Fixed	limit(0.99f);

	k1 = (det(point, cN) - det(a, cN)) / (det(bN, cN));
	k2 = (det(point, bN) - det(a, bN)) / (det(bN, cN)) * -1;
	if (k1 <= 0 || k2 <= 0 || (k1 + k2) >= limit)
		return (false);
	return (true);
}
