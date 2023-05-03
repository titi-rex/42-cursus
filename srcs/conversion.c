/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:05:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 16:47:33 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sizeof_uint(unsigned int u, int flags[3])
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
		if (flags[0] & ALTERNATE)
			size += 2;
	}
	else if (flags[3] == 'o')
	{
		size = ft_numlen(u, 8);
		if (flags[0] & ALTERNATE)
			size += 1;
	}
	return (size);
}


int	get_uint(t_print_buffer *p, unsigned int number, int base, int flags[3])
{
	int	w_len;
	int	pow;

	w_len = 0;
	dprintf(2, "get int launched, int to print : %u\tlen : %d\n", number, size);
	if (flags[0] & PLUS)
		p->buffer[p->idx] = '+';
	else if (flags[0] & BLANK)
		p->buffer[p->idx] = ' ';
	if (flags[0] & PRECISION)
		w_len = padding(p, '0', flags[2] - size);
	pow = ft_power_recursive(base, size - 1);
	while (pow)
	{
		dprintf(2, " number : %d\tpow %d\ttmp %d\tnext number %d\n", number, pow, number / pow, number - ((number / pow) * pow));
		p->buffer[p->idx] = "0123456789abcdef"[(number / pow)];
		++p->idx;
		if (p->idx == BUFFER_SIZE)
			w_len += ft_flush_buffer(p);
		number = number - ((number / pow) * pow);
		pow /= 10;
	}
	return (w_len);
}


int	conversion_uint(t_print_buffer *p, va_list ap, int flags[3], int base)
{
	unsigned int	u;
	int				w_len;
	int				size;
	int				tmp;

	u = va_arg(ap, unsigned int);
	size = sizeof_uint(u, flags[3])
	tmp = ft_max(size, flags[2]);
	w_len += pad_adjust_right(p, tmp, flags);
	w_len += get_uint(p, u, base, flags);
	w_len += pad_adjust_left(p, tmp, flags);
	return (w_len);
}

