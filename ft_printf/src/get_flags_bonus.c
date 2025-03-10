/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:37:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/20 21:17:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	get_specifier(int flags[4], char c)
{
	if (!is_specifier(c))
		return (1);
	flags[3] = c;
	if (flags[3] == 'p' || flags[3] == 'c' || flags[3] == 's' || \
		flags[3] == '%')
	{
		if (flags[0] & ZERO)
			flags[0] ^= ZERO;
	}
	if (flags[3] == 'p')
		flags[0] |= ALTERNATE;
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
	if (*str == '.' && (ft_isdigit(*(str + 1)) || is_specifier(*(str + 1))))
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

int	get_flags_error(const char **str)
{
	int	w_len;

	w_len = 0;
	while (**str)
	{
		w_len += write(1, *str, 1);
		++(*str);
	}
	return (w_len);
}
