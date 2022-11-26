/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:26:35 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/26 15:06:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr_rec(void *p)
{
	long long	val;
	int			len;
	char		*base;

	len = 0;
	val = (long long)p;
	base = "0123456789abcdef";
	if (val < 16)
		len += write(1, &base[val], 1);
	if (val >= 16)
	{
		len += ft_putadr_rec((void *)(val / 16));
		len += ft_putadr_rec((void *)(val % 16));
	}
	return (len);
}

int	ft_putadr(void *p)
{
	int		len;

	len = 0;
	len += write(1, "0x", 2);
	if (p)
		len += ft_putadr_rec(p);
	else
		len += ft_putchar('0');
	return (len);
}
