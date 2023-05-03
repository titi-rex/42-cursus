/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:37:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 21:32:10 by tlegrand         ###   ########.fr       */
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

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	get_sign(int flag[4], int d)
{
	if (flag[3] == 'c' || flag[3] == 's' || flag[3] == 'p')
		return (-1);
	if ((flag[4] == 'd' || flag[4] == 'i') && d < 0)
		return ('-');
	if (flag[0] & PLUS)
		return ('+');
	if (flag[0] & BLANK)
		return (' ');
	if (flag[0] & ALTERNATE)
	{
		if (flag[3] == 'b')
			return ('0');
		if (flag[3] == 'o')
			return ('0');
		if (flag[3] == 'x' || flag[3] == 'X')
			return ('0');
	}
	return (-1);
}

int	get_base(int flag)
{
	if (flag == 'b')
		return (2);
	if (flag == 'o')
		return (8);
	if (flag == 'd' || flag == 'i' || flag == 'u')
		return (10);
	if (flag == 'x' || flag == 'X')
		return (16);
	return (-1);
}
