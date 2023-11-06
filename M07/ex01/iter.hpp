/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:37:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/06 12:55:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITER_H__
# define _ITER_H__

template <typename T, typename F>
void	iter(T a, size_t len, F f)
{
	if (!a)
		return ;
	for (size_t i = 0; i < len; ++i)
		f(a[i]);
}

#endif
