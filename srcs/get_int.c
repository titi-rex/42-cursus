/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:35:21 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 21:22:51 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sizeof_int(int d, int flags[4])
{
	int	size;

	if (flags[3] == 'c')
		return (1);
	size = ft_numlen(d, 10);
	return (size);
}

int	get_int(t_print_buffer *p, int number, int size, int flags[4])
{
	int	w_len;
	int	pow;

	w_len = 0;
	if (flags[0] & PRECISION)
		w_len = padding(p, '0', flags[2] - size);
	pow = ft_power_recursive(10, size - 1);
	while (pow)
	{
		w_len += write_buffer(p, (number / pow) + '0');
		number = number - ((number / pow) * pow);
		pow /= 10;
	}
	return (w_len);
}

int	conversion_int(t_print_buffer *p, va_list ap, int flags[4])
{
	int	d;
	int	w_len;
	int	size;
	int	tmp;

	w_len = 0;
	d = va_arg(ap, int);
	size = sizeof_int(d, flags);
	tmp = ft_max(size, flags[2]);
	w_len += pad_adjust_right(p, tmp, get_sign(flags, d), flags);
	d = ft_abs(d);
	if (flags[3] == 'c')
		w_len += write_buffer(p, d);
	else
		w_len += get_int(p, d, size, flags);
	w_len += pad_adjust_left(p, tmp, flags);
	return (w_len);
}
