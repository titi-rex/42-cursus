/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:35:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/06/06 21:24:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	padding(char c, int size)
{
	int	w_len;

	w_len = 0;
	while (size-- > 0)
		w_len += write(1, &c, 1);
	return (w_len);
}

int	write_sign(int sign, int specifier, int flag)
{
	int	w_len;

	w_len = 0;
	if (sign != -1 && specifier == 'p' && flag & BLANK)
		w_len += write(1, " ", 1);
	if (sign != -1)
		w_len += write(1, &sign, 1);
	if (sign == '0' && (specifier == 'x' || specifier == 'p'))
		w_len += write(1, "x", 1);
	else if (sign == '0' && specifier == 'X')
		w_len += write(1, "X", 1);
	else if (sign == '0' && specifier == 'b')
		w_len += write(1, "b", 1);
	return (w_len);
}

int	pad_adjust_right(int size, int sign, int flags[4])
{
	int	w_len;

	w_len = 0;
	if (sign != -1)
		--flags[1];
	if (sign == '0' && flags[3] != 'o')
		--flags[1];
	if ((flags[0] & LEFT) == 0 && flags[1] > size)
	{
		if ((flags[0] & PRECISION) == 0 && (flags[0] & ZERO))
		{
			w_len += write_sign(sign, flags[3], flags[0]);
			w_len += padding('0', flags[1] - size);
		}
		else
		{
			w_len += padding(' ', flags[1] - size);
			w_len += write_sign(sign, flags[3], flags[0]);
		}
	}
	else
		w_len += write_sign(sign, flags[3], flags[0]);
	return (w_len);
}

int	pad_adjust_left(int size, int flags[4])
{
	int	w_len;

	w_len = 0;
	if ((flags[0] & LEFT) && flags[1] > size)
		w_len += padding(' ', flags[1] - size);
	return (w_len);
}
