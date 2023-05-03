/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:05:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 21:31:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sizeof_uint(unsigned int u, int flags[4])
{
	int	size;

	size = -1;
	if (flags[3] == 'p')
	{
		if (u)
			size = ft_numlen(u, 16) + 2;
		else
			size = 5;
	}
	else if (flags[3] == 'x' || flags[3] == 'X')
	{
		size = ft_numlen(u, 16);
	}
	else if (flags[3] == 'o')
	{
		size = ft_numlen(u, 8);
		if (flags[0] & ALTERNATE)
			size += 1;
	}
	else if (flags[3] == 'b')
	{
		size = ft_numlen(u, 2);
		if (flags[0] & ALTERNATE)
			size += 2;
	}
	else if (flags[3] == 'u')
		size = ft_numlen(u, 10);
	return (size);
}

int	get_uint(t_print_buffer *p, unsigned int number, int size, int flags[4])
{
	char	*base;
	int		w_len;
	int		pow;
	int		base_len;

	w_len = 0;
	base_len = get_base(flags[3]);
	if (flags[3] == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (flags[0] & PRECISION)
		w_len += padding(p, '0', flags[2] - size);
	pow = ft_power_recursive(base_len, size - 1);
	while (pow)
	{
		w_len += write_buffer(p, base[(number / pow)]);
		number = number - ((number / pow) * pow);
		pow /= base_len;
	}
	return (w_len);
}

int	conversion_uint(t_print_buffer *p, va_list ap, int flags[4])
{
	unsigned int	u;
	int				w_len;
	int				size;
	int				tmp;

	w_len = 0;
	u = va_arg(ap, unsigned int);
	size = sizeof_uint(u, flags);
	tmp = ft_max(size, flags[2]);
	w_len += pad_adjust_right(p, tmp, get_sign(flags, u), flags);
	w_len += get_uint(p, u, size, flags);
	w_len += pad_adjust_left(p, tmp, flags);
	return (w_len);
}

// dprintf(2, "get int launched, int to print : %u\tlen : %d\n", number, size);
// dprintf(2, " number : %d\tpow %d\ttmp %d\tnext number %d\n", number, pow, number / pow, number - ((number / pow) * pow));
