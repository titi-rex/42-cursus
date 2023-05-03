/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:43:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 21:35:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flush_buffer(t_print_buffer *p)
{
	int	w_len;

	if (p->idx)
		w_len = write(1, p->buffer, p->idx);
	p->idx = 0;
	return (w_len);
}

int	write_buffer(t_print_buffer *p, char c)
{
	int	w_len;
	w_len = 0;
	
	p->buffer[p->idx] = c;
	++p->idx;
	if (p->idx == BUFFER_SIZE)
		w_len += flush_buffer(p);
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
	if (flags[3] == 'c' || flags[3] == 'd' || flags[3] == 'i')
		conversion_int(p, ap, flags);
	else if (flags[3] == 'x' || flags[3] == 'X' || flags[3] == 'u' || flags[3] == 'o')
		conversion_uint(p, ap, flags);
	// else if (flags[3] == 'p')
		// conversion_ptr(p, ap, flags, get_base(flags[2]));
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
			w_len += write_buffer(&p, *str);
		++str;
		if (!*str)
			w_len += flush_buffer(&p);
	}
	va_end(ap);
	return (w_len);
}

int	main(void)
{
	char			*ptr;
	int	u;

	ptr = "hello";
	(void)ptr;
	u = 4;
	(void)u;
	printf("ret : %d\n", ft_printf("hello :%#b: non\n", u));
	printf("trueret : %d\n", printf("hello :%#x: non\n", u));
}
