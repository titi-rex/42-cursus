/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:35:21 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 16:42:30 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	get_char(t_print_buffer *p, char c)
{
	int	w_len;

	w_len = 0;
	p->buffer[p->idx] = c;
	if (p->idx == BUFFER_SIZE)
		w_len += ft_flush_buffer(p);
	return (w_len);
}

/*
int	get_str(t_print_buffer *p, char *str, int flags[3])
{
	int	w_len;

	
	w_len = 0;
	return (w_len);
}
*/


int	get_int(t_print_buffer *p, int number, int size, int flags[3])
{
	int	w_len;
	int	pow;

	w_len = 0;
	dprintf(2, "get int launched, int to print : %d\tlen : %d\n", number, size);
	if (flags[0] & PLUS)
		p->buffer[p->idx] = '+';
	else if (flags[0] & BLANK)
		p->buffer[p->idx] = ' ';
	if (flags[0] & PRECISION)
		w_len = padding(p, '0', flags[2] - size);
	pow = ft_power_recursive(10, size - 1);
	while (pow)
	{
		dprintf(2, " number : %d\tpow %d\ttmp %d\tnext number %d\n", number, pow, number / pow, number - ((number / pow) * pow));
		p->buffer[p->idx] = (number / pow) + '0';
		++p->idx;
		if (p->idx == BUFFER_SIZE)
			w_len += ft_flush_buffer(p);
		number = number - ((number / pow) * pow);
		pow /= 10;
	}
	return (w_len);
}
