/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:05:47 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/25 18:50:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_select_print(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	// else if (c == 'p')
	// 	return (ft_putmem_fd(va_arg(ap, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789"));
	// else if (c == 'u')
	// 	return (ft_putui(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		n;
	char	*idset;
	char	*format;
	va_list	ap;


	idset = "cspdiuxX";
	va_start(ap, str);
	n = 0;
	while (*str)
	{
		format = ft_strchr(idset, (int)*(str + 1));
		if (*str == '%')
		{
			str++;
			if (format != NULL)
				n += ft_select_print(*format, ap);
			else
				n += ft_putchar(*str);
		}
		else
			n += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (n);
}



/*

size_t	ft_countarg(char *str, char *set)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		if (*str == '%' && ft_strchr(set, (int)*(str + 1)) != NULL)
			n++;
		str++;
	}
	return (n);
}

*/