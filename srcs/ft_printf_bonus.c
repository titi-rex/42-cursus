/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:43:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/06 22:51:06 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	selector(t_print_buffer *p, const char **str, va_list ap)
{
	int	flags[4];
	int	w_len;

	w_len = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	if (get_flags(*str, flags))
		return (get_flags_error(p, str));
	if (flags[3] == '%')
		w_len += write_buffer(p, '%');
	else if (flags[3] == 'c' || flags[3] == 'd' || flags[3] == 'i')
		get_int(p, ap, flags);
	else if (flags[3] == 'x' || flags[3] == 'X' || flags[3] == 'u' || \
		flags[3] == 'o' || flags[3] == 'b' || flags[3] == 'p')
		get_uint(p, ap, flags);
	else if (flags[3] == 's')
		get_str(p, ap, flags);
	++(*str);
	while (**str && **str != flags[3])
		++(*str);
	return (w_len);
}

int	ft_printf(const char *str, ...)
{
	t_print_buffer	p;
	va_list			ap;
	int				w_len;
	int				err;

	va_start(ap, str);
	w_len = 0;
	err = 0;
	p.idx = 0;
	while (*str)
	{
		if (*str == '%')
			w_len += selector(&p, &str, ap);
		else
			w_len += write_buffer(&p, *str);
		if (*str)
			++str;
		if (w_len < 0)
			err = -1;
	}
	w_len += flush_buffer(&p);
	va_end(ap);
	if (err)
		return (-1);
	return (w_len);
}
