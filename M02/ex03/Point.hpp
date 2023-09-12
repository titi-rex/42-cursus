/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:32:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 14:59:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_H__
# define _POINT_H__
# include <iostream>
# include "Fixed.hpp"

class Point 
{
	
	private	:
		Fixed const	_x;
		Fixed const	_y;
		std::string	_name;

	public	:

		Point(void);
		Point(const Point& cpy);
		Point&	operator=(const Point& cpy);
		~Point(void);

		Point(const float x, const float y);

		Fixed const	getX(void) const;
		Fixed const	getY(void) const;
		
		std::string getName(void) const;
		void 		setName(std::string name);

		void	info(void) const;
};

#endif
