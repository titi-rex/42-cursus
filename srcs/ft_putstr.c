/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:59:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/06 22:32:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		len += ft_putchar(*s);
		s++;
		if (len == -1)
			return (len);
	}
	return (len);
}
