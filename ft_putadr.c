/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:26:35 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/26 17:35:39 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr_rec(void *p)
{
	unsigned long long	val;
	int					len;
	char				*base;

	len = 0;
	val = (unsigned long long)p;
	base = "0123456789abcdef";
	if (val < 16)
		return (write(1, &base[val], 1));
	if (val >= 16)
	{
		len += ft_putadr_rec((void *)(val / 16));
		if (len == -1)
			return (len);
		len += ft_putadr_rec((void *)(val % 16));
		if (len == -1)
			return (len);
	}
	return (len);
}

int	ft_putadr(void *p)
{
	int		len;

	len = 0;
	len += write(1, "0x", 2);
	if (len == -1)
		return (len);
	len += ft_putadr_rec(p);
	return (len);
}
