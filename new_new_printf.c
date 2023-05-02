/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_new_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:43:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/02 16:48:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)(s + n) = 0;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return ((int) sign * res);
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-')
		return (LEFT);
	if (c == '0')
		return (ZERO);
	if (c == ' ')
		return (BLANK);
	if (c == '+')
		return (PLUS);
	if (c == '#')
		return (ALTERNATE);
	return (0);
}

int	get_flags(char *str, int flags[3])
{
	int	bit;

	bit = is_flag(*str);
	while (*str && !is_specifier(*str) && bit)
	{
		if (flags[0] & bit)
			return (1);
		flags[0] |= bit;
		++str;
		bit = is_flag(*str);
	}
	flags[1] = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		++str;
	if (*str == '.' && ft_isdigit(*(str + 1)))
	{
		flags[0] |= PRECISION;
		flags[2] = ft_atoi(++str);
		while (*str && ft_isdigit(*str))
			++str;
	}
	if (!is_specifier(*str))
		return (1);
	flags[3] = *str;
	return (0);
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
int	ft_numlen(long long int num, int base)
{
	int	len;

	len = 1;
	while (num)
	{
		num /= base;
		++len;
	}
	return (len);
}

/*
c p no preci 

else preci 
*/

int	padding(t_print_buffer *p, char c, int size)
{
	int	w_len;

	w_len = 0;
	while (size-- > 0)
	{
		p->buffer[p->idx] = c;
		++p->idx;
		if (p->idx == BUFFER_SIZE)
			w_len += ft_flush_buffer(p);
	}
	return (w_len);
}

int	get_char(t_print_buffer *p, char c)
{
	int	w_len;

	w_len = 0;
	p->buffer[p->idx] = c;
	if (p->idx == BUFFER_SIZE)
		w_len += ft_flush_buffer(p);
	return (w_len);
}

int	get_str(t_print_buffer *p, char *str, int flags[3])
{
	int	w_len;

	w_len = 0;
	return (w_len);
}

int	get_uint(t_print_buffer *p, unsigned int number, int base, int flags[3])
{
	int	w_len;

	w_len = 0;
	return (w_len);
}

int	get_int(t_print_buffer *p, int number, int size, int flags[3])
{
	int	w_len;
	int	pow;

	w_len = 0;
	if (flags[0] & PLUS)
		p->buffer[p->idx] = '+';
	else if (flags[0] & BLANK)
		p->buffer[p->idx] = ' ';
	// if (flags[0] & PRECISION)
	// 	w_len = padding(p, '0', flags[3] - size)
	pow = ft_power(10, size);
	while (number)
	{
		p->buffer[p->idx] = (number / pow);
		if (p->idx == BUFFER_SIZE)
			w_len += ft_flush_buffer(p);
	}
	return (w_len);
}

/*
0 padding with c or s or p undifined

*/

int	get_conversion(t_print_buffer *p, const char *str, va_list ap, int flags[3])
{
	int	w_len;
	int	size;
	int	tmp;
	int	d;

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
	if (size < flags[2])
		tmp = flags[2];
	if (flags[0] & LEFT == 0 && flags[1] > tmp)
	{
		if (flags[0] & PLUS || flags[0] & BLANK)
			--flags[1];
		if (flags[0] & PRECISION == 0 && flags[0] & ZERO)
			w_len += padding(p, '0', flags[1] - tmp);
		else
			w_len += padding(p, ' ', flags[1] - tmp);
	}
	if (flags[3] == 'd' || flags[3] == 'i')
		w_len += get_int(p, d, size, flags);
	else if (flags[3] == 'c')
		w_len += get_char(p, d);
	return (w_len);
}


int	ft_select_print(t_print_buffer *p, const char *str, va_list ap)
{
	int	i;
	int	flags[4];
	int	w_len;

	w_len = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	++str;
	if (get_flag(str, flags) == -1)
		return (0);
	get_conversion(p, str, ap, flags);

	return (w_len);
}

int	ft_flush_buffer(t_print_buffer *p)
{
	int	w_len;

	w_len = write(1, p->buffer, p->idx);
	p->idx = 0;
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
			w_len += ft_select_print(&p, str, ap);
		else
			p.buffer[p.idx] = *str;
		++str;
		++p.idx;
		if (p.idx == BUFFER_SIZE)
			w_len += ft_flush_buffer(&p);
		if (!*str)
			w_len += ft_flush_buffer(&p);
	}
	va_end(ap);
	return (w_len);
}

int	main(void)
{
	printf("ret : %d\n", ft_printf("hello 15 non\n"));
	printf("trueret : %d\n", printf("hello 15 non\n"));
}
