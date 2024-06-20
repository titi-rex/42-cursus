/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:10:24 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/16 10:38:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TEMPLATE_H__
# define _TEMPLATE_H__

template <typename T> void swap(T& a, T& b)
{
	T	tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T& a, T& b)
{
	return ((a < b) ? a : b);
}

template <typename T> T max(T& a, T& b)
{
	return ((a > b) ? a : b);
}

#endif
