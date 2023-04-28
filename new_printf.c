/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:05:55 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/28 23:31:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_specifier(char c)
{
	if (c == 'c' || c == ' s' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'o' || c == ' u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	get_size(char *str)
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

int	ft_printf(const char *str, ...)
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
		return (NULL);
	tab[n_chunk] = NULL;
	va_start(ap, str);
	i = -1;
	len = 0;
	while (++i < n_chunk)
	{
		if (*str == '%')
			tab[i] = extract_conv(&str, ap);
		else
			tab[i] = extract_string(&str);
		if (!tab[i])
			return (NULL);
	}
	va_end(ap);
	to_print = multijoin(tab);
	while (to_print[len])
		++len;
	write(1, to_print, len);
	return (len);
}

char	*extract_string(char **str)
{
	char	*extracted;
	int		len;
	int		i;

	len = 0;
	while (*str[len] && *str[len] != '%')
		++len;
	extracted = malloc((len + 1) * sizeof(char));
	if (!extracted)
		return (NULL);
	i = -1;
	while (++i < len)
		extracted[i] = *str[i];
	extracted[i] = '\0';
	*str += len;
	return (extracted);
}
