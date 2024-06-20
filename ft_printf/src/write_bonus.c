/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:13:55 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/06 23:11:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	write_str(char *str, int max)
{
	int	w_len;

	w_len = 0;
	if (max < 0)
	{
		while (*str)
		{
			w_len += write(1, str, 1);
			++str;
		}
		return (w_len);
	}
	while (*str && max > 0)
	{
		w_len += write(1, str, 1);
		++str;
		--max;
	}
	return (w_len);
}
