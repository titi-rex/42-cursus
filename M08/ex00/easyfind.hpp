/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:57:46 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/07 11:42:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EASYFIND_H__
# define _EASYFIND_H__
# include <algorithm>
# include <stdexcept>
#include <iostream>

template <typename T>
void	easyfind(T& ctr, int val)
{
	typename T::iterator	it;

	it = std::find(ctr.begin(), ctr.end(), val);
	if (it == ctr.end())
		throw std::invalid_argument("Error: value not found");
	else
		std::cout << "euhh " << *ctr.end() << std::endl;
}

#endif
