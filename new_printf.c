/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:05:55 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/29 23:20:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	get_size(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		++i;
		if (*str != '%')
		{
			while (*str != '%' && *str)
				++str;
		}
		else if (*str == '%')
		{
			++i;
			while (*str && is_specifier(*str))
				++str;
			if (*str)
				++str;
		}
	}
	return (i);
}

char *extract_conv(const char **format, va_list ap)
{
	char	*str;
	int		n;

	n = va_arg(ap, int);
	str = malloc (3 * sizeof(char));
	str[0] = 48;
	str[1] = 51;
	str[2] = 0;
	(void)n;
	*format += 2;
	return (str);
}

char	*extract_string(const char **format)
{
	char	*str;
	char	*extracted;
	int		len;
	int		i;

	str = (char *) *format;
	dprintf(2, " OKi\n");
	len = 0;
	while (str[len] && str[len] != '%')
		++len;
	extracted = malloc((len + 1) * sizeof(char));
	if (!extracted)
		return (NULL);
	i = -1;
	while (++i < len)
		extracted[i] = str[i];
	extracted[i] = '\0';
	*format += len;
	return (extracted);
}

int	ft_printf2(const char *str, ...)
{
	char	**tab;
	char	*to_print;
	int		n_chunk;
	int		i;
	int		len;
	va_list	ap;

	n_chunk = get_size(str);
	tab = malloc((n_chunk + 1) * sizeof(void *));
	if (!tab)
		return (-1);
	tab[n_chunk] = NULL;
	va_start(ap, str);
	i = -1;
	dprintf(2, " OK\n");
	while (++i < n_chunk)
	{
		if (*str == '%')
			tab[i] = extract_conv(&str, ap);
		else
			tab[i] = extract_string(&str);
		if (!tab[i])
			return (-1);
		dprintf(2, " OK\n");
	}
	va_end(ap);
	len = 0;
	i = 0;
	to_print = tab[0];
	while (to_print[len])
		++len;
	write(1, to_print, len);
	i += len;
	len = 0;
	to_print = tab[1];
	while (to_print[len])
		++len;
	write(1, to_print, len);
	i += len;
	len = 0;
	to_print = tab[2];
	while (to_print[len])
		++len;
	write(1, to_print, len);
	i += len;
	return (i);
}


int	main(void)
{
	printf("ret : %d\n", ft_printf2("hello %d non\n"));
	printf("trueret : %d\n", printf("hello %d non\n", 13));
}
