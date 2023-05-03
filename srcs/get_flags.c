/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:37:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 21:24:11 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flags(const char *str, int flags[4])
{
	int	bit;

	bit = is_flag(*(++str));
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
	if (flags[3] == 'p' || flags[3] == 'c' || flags[3] == 's')
		if (flags[0] & ZERO)
			flags[0] ^= ZERO;
	return (0);
}

void	print_flags(int flags[4])
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
