/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:34:54 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 21:36:05 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)(s + n) = 0;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			sign;

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
		res = res * 10 + (*str - 48);
		str++;
	}
	return ((int) sign * res);
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == '%' || c == 'b')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-')
		return (LEFT);
	if (c == '0')
		return (ZERO);
	if (c == ' ')
		return (BLANK);
	if (c == '+')
		return (PLUS);
	if (c == '#')
		return (ALTERNATE);
	return (0);
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
