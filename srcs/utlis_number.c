/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:37:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 16:13:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(long long int num, int base)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num)
	{
		num /= base;
		++len;
	}
	return (len);
}

/*
c p no preci 

else preci 
*/

int	ft_power_recursive(int nb, int power)
{
	int		res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (res);
	if (power > 1)
		res *= ft_power_recursive(nb, power - 1);
	res *= nb;
	return (res);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
