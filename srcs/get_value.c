/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:35:21 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/04 13:29:54 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_sign(int flag[4], int d)
{
	if (flag[3] == 'c' || flag[3] == 's')
		return (-1);
	if ((flag[3] == 'd' || flag[3] == 'i') && d < 0)
		return ('-');
	if (flag[0] & PLUS)
		return ('+');
	if (flag[0] & BLANK)
		return (' ');
	if (flag[0] & ALTERNATE)
	{
		if (flag[3] == 'p' && d == 0)
			return (-1);
		else if (flag[3] == 'p')
			return ('0');
		if (flag[3] == 'b')
			return ('0');
		if (flag[3] == 'o')
			return ('0');
		if (flag[3] == 'x' || flag[3] == 'X')
			return ('0');
	}
	return (-1);
}

static int	get_size(unsigned int u, int flags[4])
{
	if (flags[3] == 'c')
		return (1);
	if (flags[3] == 'p')
	{
		if (u)
			return (ft_numlen(u, 16));
		else
			return (5);
	}
	else if (flags[3] == 'x' || flags[3] == 'X')
		return (ft_numlen(u, 16));
	else if (flags[3] == 'o')
		return (ft_numlen(u, 8));
	else if (flags[3] == 'b')
		return (ft_numlen(u, 2));
	else if (flags[3] == 'u' || flags[3] == 'd')
		return (ft_numlen(u, 10));
	return (-1);
}

int	get_int(t_print_buffer *p, va_list ap, int flags[4])
{
	int	d;
	int	w_len;
	int	size;
	int	tmp;
	int	sign;

	w_len = 0;
	if (flags[3] == '%')
		d = '%';
	else
		d = va_arg(ap, int);
	sign = get_sign(flags, d);
	d = ft_abs(d);
	size = get_size(d, flags);
	tmp = ft_max(size, flags[2]);
	w_len += pad_adjust_right(p, tmp, sign, flags);
	if (flags[3] == 'c' || flags[3] == '%')
		w_len += write_buffer(p, d);
	else
		w_len += extract_number(p, d, size, flags);
	w_len += pad_adjust_left(p, tmp, flags);
	return (w_len);
}

int	get_uint(t_print_buffer *p, va_list ap, int flags[4])
{
	unsigned long int	u;
	int					w_len;
	int					size;
	int					tmp;

	w_len = 0;
	u = va_arg(ap, unsigned long int);
	size = get_size(u, flags);
	tmp = ft_max(size, flags[2]);
	w_len += pad_adjust_right(p, tmp, get_sign(flags, u), flags);
	if (u == 0 && flags[3] == 'p')
		w_len += write_buffer_str(p, "(nil)");
	else
		w_len += extract_number(p, u, size, flags);
	w_len += pad_adjust_left(p, tmp, flags);
	return (w_len);
}

int	get_str(t_print_buffer *p, va_list ap, int flags[4])
{
	char	*str;
	int		w_len;
	int		size;
	int		tmp;

	w_len = 0;
	str = va_arg(ap, char *);
	size = ft_strlen2(str);
	if (size == 0)
		size = 6;
	tmp = ft_max(size, flags[2]);
	w_len += pad_adjust_right(p, tmp, -1, flags);
	if (str == NULL)
		w_len += write_buffer_str(p, "(null)");
	else
		w_len += write_buffer_str(p, str);
	w_len += pad_adjust_left(p, tmp, flags);
	return (w_len);
}
