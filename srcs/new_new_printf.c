/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_new_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:43:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 16:49:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flush_buffer(t_print_buffer *p)
{
	int	w_len;

	w_len = write(1, p->buffer, p->idx);
	p->idx = 0;
	return (w_len);
}

int	padding(t_print_buffer *p, char c, int size)
{
	int	w_len;

	w_len = 0;
	while (size-- > 0)
	{
		dprintf(2, " pad size %d \n", size);
		p->buffer[p->idx] = c;
		++p->idx;
		if (p->idx == BUFFER_SIZE)
			w_len += ft_flush_buffer(p);
	}
	return (w_len);
}


/*
get flag width preci and specifier

print padd if width exist and not left adj -
with 0 if zero exist 0


blank or + before number 
# alternat form number
. precision number / string 

print pad if widt exist and left adj -

*/



/*
0 padding with c or s or p undifined

*/

int	pad_adjust_right(t_print_buffer *p, int size, int flags[3])
{
	int	w_len;

	w_len = 0;
	if ((flags[0] & LEFT) == 0 && flags[1] > size)
	{
		if ((flags[0] & PLUS) || (flags[0] & BLANK))
			--flags[1];
		if ((flags[0] & PRECISION) == 0 && (flags[0] & ZERO))
			w_len += padding(p, '0', flags[1] - size);
		else
			w_len += padding(p, ' ', flags[1] - size);
	}
	return (w_len);
}

int	pad_adjust_left(t_print_buffer *p, int size, int flags[3])
{
	int	w_len;

	w_len = 0;
	if ((flags[0] & LEFT) && flags[1] > size)
			w_len += padding(p, ' ', flags[1] - size);
	return (w_len);
}

int	get_conversion(t_print_buffer *p, va_list ap, int flags[3])
{
	int				w_len;
	int				size;
	int				tmp;
	char			*str;
	int				d;

	w_len = 0;
	if (flags[3] == 'd' || flags[3] == 'i')
	{
		d = va_arg(ap, int);
		size = ft_numlen(d, 10);
	}
	else if (flags[3] == 'c')
	{
		d = va_arg(ap, int);
		size = 1;
	}
	else if (flags[3] == 's')
	{
		str = va_arg(ap, char *);
		if (str)
			size = ft_strlen2(str);
		else
			size = 6;
	}
	dprintf(2, "flags 2 : %d\tsize : %d\n", flags[2], size);
	tmp = ft_max(size, flags[2]);
	w_len += pad_adjust_right(p, tmp, flags);
	if (flags[3] == 'd' || flags[3] == 'i')
		w_len += get_int(p, d, size, flags);
	else if (flags[3] == 'c')
		w_len += get_char(p, d);
	w_len += pad_adjust_left(p, tmp, flags);
	return (w_len);
}

int	ft_select_print(t_print_buffer *p, const char **str, va_list ap)
{
	int	flags[4];
	int	w_len;

	w_len = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	if (get_flags(*str, flags) == -1)
		return (0);
	print_flags(flags);
	if (flags[3] == 'x' || flags[3] == 'X' || flags[3] == 'p')
	get_conversion(p, ap, flags);
	while (**str && **str != flags[3])
		++(*str);
	return (w_len);
}

int	ft_printf(const char *str, ...)
{
	t_print_buffer	p;
	int				w_len;
	va_list			ap;

	va_start(ap, str);
	w_len = 0;
	p.idx = 0;
	while (*str)
	{
		if (*str == '%')
			w_len += ft_select_print(&p, &str, ap);
		else
		{
			p.buffer[p.idx] = *str;
			++p.idx;
		}
		++str;
		if (!*str || p.idx == BUFFER_SIZE)
			w_len += ft_flush_buffer(&p);
	}
	va_end(ap);
	return (w_len);
}

int	main(void)
{
	char			*ptr;
	unsigned int	u;

	ptr = "hello";
	(void)ptr;
	u = 119;
	(void)u;
	//printf("ret : %d\n", ft_printf("hello %04d non\n", u));
	printf("trueret : %d\n", printf(":%0-10d:\n:%d:\n", u, u));
}
