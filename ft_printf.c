/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:05:47 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/28 15:53:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_select_print(char c, va_list ap)
{
	char	*base_lx;
	char	*base_ux;

	base_lx = "0123456789abcdef";
	base_ux = "0123456789ABCDEF";
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putadr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base((unsigned int)va_arg(ap, int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base((unsigned int)va_arg(ap, int), base_lx));
	else if (c == 'X')
		return (ft_putnbr_base((unsigned int)va_arg(ap, int), base_ux));
	else
		return (ft_putchar(c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		n;
	va_list	ap;

	va_start(ap, str);
	n = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			n += ft_select_print(*str, ap);
		}
		else
			n += ft_putchar(*str);
		str++;
		if (n == -1)
			return (n);
	}
	va_end(ap);
	return (n);
}
