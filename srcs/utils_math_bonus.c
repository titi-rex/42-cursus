/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:37:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/05 22:35:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

unsigned long long int	ft_power_recursive(unsigned long long int nb, int power)
{
	unsigned long long int		res;

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

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

long int	ft_abs(long int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
