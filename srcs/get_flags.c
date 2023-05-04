/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:37:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/04 13:18:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_specifier(int flags[4], char c)
{
	if (!is_specifier(c))
		return (1);
	flags[3] = c;
	if (flags[3] == 'p' || flags[3] == 'c' || flags[3] == 's')
		if (flags[0] & ZERO)
			flags[0] ^= ZERO;
	if (flags[3] == 'p')
	{
		flags[0] |= ALTERNATE;
		flags[0] |= PRECISION;
		flags[2] = 12;
	}
	return (0);
}

int	get_flags(const char *str, int flags[4])
{
	int	bit;

	bit = is_flag(*(++str));
	while (*str && !is_specifier(*str) && bit)
	{
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
	if (get_specifier(flags, *str))
		return (1);
	return (0);
}

int	get_flags_error(t_print_buffer *p, const char *str)
{
	int	w_len;

	w_len = 0;
	while (*str)
	{
		w_len += write_buffer(p, *str);
		++str;
	}
	return (w_len);
}

void	debug_print_flags(int flags[4])
{
	if (flags[0] == 0)
		dprintf(2, "NO FLAGS ");
	if (flags[0] & LEFT)
		dprintf(2, "LEFT ");
	if (flags[0] & PRECISION)
		dprintf(2, "PRECISION ");
	if (flags[0] & ZERO)
		dprintf(2, "ZERO ");
	if (flags[0] & BLANK)
		dprintf(2, "BLANK ");
	if (flags[0] & PLUS)
		dprintf(2, "PLUS ");
	if (flags[0] & ALTERNATE)
		dprintf(2, "ALTERNATE ");
	dprintf(2, "\nwidth : %d\n", flags[1]);
	dprintf(2, "precision : %d\n", flags[2]);
	dprintf(2, "specifier : %c\n", flags[3]);
}
