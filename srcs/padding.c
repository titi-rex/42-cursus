/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:35:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 21:34:51 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding(t_print_buffer *p, char c, int size)
{
	int	w_len;

	w_len = 0;
	while (size-- > 0)
	{
		w_len += write_buffer(p, c);
		dprintf(2, " pad size %d \n", size);
	}
	return (w_len);
}

int	write_sign(t_print_buffer *p, int sign, int specifier)
{
	int	w_len;

	w_len = 0;
	dprintf(2, "sign %d\tspecifier %c\n", sign, specifier);
	if (sign != -1)
		w_len += write_buffer(p, sign);
	if (sign == '0' && specifier != 'o')
			w_len += write_buffer(p, specifier);
	return (w_len);
}

int	pad_adjust_right(t_print_buffer *p, int size, int sign, int flags[4])
{
	int	w_len;

	w_len = 0;
	if (sign != -1)
		--flags[1];
	if (sign == 0 && flags[3] != 'o')
		--flags[1];
	dprintf(2, "width %d\n", flags[1]);
	if ((flags[0] & LEFT) == 0 && flags[1] > size)
	{
		if ((flags[0] & PRECISION) == 0 && (flags[0] & ZERO))
		{
			w_len += write_sign(p, sign, flags[3]);
			w_len += padding(p, '0', flags[1] - size);
		}
		else
		{
			w_len += padding(p, ' ', flags[1] - size);
			w_len += write_sign(p, sign, flags[3]);
		}
	}
	w_len += write_sign(p, sign, flags[3]);
	return (w_len);
}

int	pad_adjust_left(t_print_buffer *p, int size, int flags[4])
{
	int	w_len;

	w_len = 0;
	if ((flags[0] & LEFT) && flags[1] > size)
			w_len += padding(p, ' ', flags[1] - size);
	return (w_len);
}
