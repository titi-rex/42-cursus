/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:45:39 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/12 19:43:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief check if overflow occur
 * 
 * @param n last result
 * @param last last char to add
 * @param sign signe of result
 * @return int OK 1 // else overflow
 */
static int	ft_check_overflow(long long int n, int last, int sign)
{
	if (sign * n != sign * (n * 10 + last) / 10)
	{
		if (sign * (n * 10 + last) / 10 < 0)
			return (-1);
		else
			return (0);
	}
	return (1);
}

/**
 * @brief convert ASCII string to long int
 * 
 * @param str 
 * @return long int 
 */
long int	ft_atol(const char *str)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ft_check_overflow(res, *str - 48, sign) != 1)
			return (ft_check_overflow(res, *str - 48, sign));
		res = res * 10 + (*str - 48);
		str++;
	}
	return ((long) sign * res);
}
