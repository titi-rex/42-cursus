/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:26:35 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/28 16:02:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr_rec(unsigned long long p)
{
	int					len;
	char				*base_lx;

	len = 0;
	base_lx = "0123456789abcdef";
	if (p >= 16)
	{
		len += ft_putadr_rec((p / 16));
		if (len == -1)
			return (len);
		len += ft_putadr_rec((p % 16));
		if (len == -1)
			return (len);
	}
	else
		return (write(1, &base_lx[p], 1));
	return (len);
}

int	ft_putadr(void *p)
{
	int		len;

	len = 0;
	len += write(1, "0x", 2);
	if (len == -1)
		return (len);
	len += ft_putadr_rec((unsigned long long)p);
	return (len);
}
