/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:05:47 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/19 16:46:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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


int	ft_select_print(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, char), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	if (c == 'p')
		ft_putmem_fd(va_arg(ap, void *), 1);
	if (c == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	if (c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	if (c == 'u')
		ft_putui_fd(va_arg(ap, unsigned int), 1);
	if (c == 'x')
		ft_puthexlow_fd(va_arg(ap, int), 1);
	if (c == 'X')
		ft_puthexup_fd(va_arg(ap, int), 1);
	if (c == '%')
		ft_putchar_fd('%', 1);
	return (0);
}

int	ft_size_format(char *str, char const *flags, char const *idset)
{
	size_t	len;

	

	return (0);
}


int	ft_printf(const char *str, ...)
{
	size_t	len_format;
	char	*flags;
	char	*idset;
	va_list	ap;

	flags = "-0. +#";
	idset = "cspdiuxX%";
	va_start(ap, str);
	while (*str)
	{
		format = ft_strchr(set, (int)*(str + 1));
		if (*str == '%' && format != NULL)
		{
			ft_select_print(*format, ap);
			va_arg(ap, void);
			str++;
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(ap);
	return (0);
}
