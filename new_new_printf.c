/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_new_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:43:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/01 20:38:05 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)(s + n) = 0;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return ((int) sign * res);
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-')
		return (HYPHEN);
	if (c == '0')
		return (ZERO);
	if (c == ' ')
		return (BLANK);
	if (c == '+')
		return (PLUS);
	if (c == '#')
		return (HASH);
	return (0);
}

int	get_flags(char *str, int flags[3])
{
	int	bit;

	bit = is_flag(*str);
	while (*str && bit)
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
		flags[0] |= DOT;
		flags[2] = ft_atoi(++str);
		while (*str && ft_isdigit(*str))
			++str;
	}
	if (!is_specifier(*str))
		return (1);
	flags[3] = *str;
	return (0);
}

/*
get flag width preci and specifier

print padd if width exist and not left adj -
with 0 if zero exist 0


blank or + before number 
# alternat form number
. precision number / string 

print pad if widt exist and left adj -

*/

int	ft_select_print(const char *str, char*buffer, va_list ap, int *idx)
{
	int	i;
	int	flags[4];
	int	len;

	len = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	++str;
	if (get_flag(str, flags) == -1)
		return (0);
	if (flags[0] & )
	return (len);
}

int	ft_flush_buffer(char *buffer, int *size)
{
	int	len;

	len = write(1, buffer, *size);
	ft_bzero(buffer, *size);
	*size = 0;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	char	buffer[BUFFER_SIZE];
	int		len;
	int		i;
	va_list	ap;

	va_start(ap, str);
	len = 0;
	i = 0;
	while (*str)
	{
		if (*str == '%')
			len += ft_select_print(str, buffer, ap, &i);
		else
			buffer[i] = *str;
		++str;
		++i;
		if (i == BUFFER_SIZE)
			len += ft_flush_buffer(buffer, &i);
		if (!*str)
			len += ft_flush_buffer(buffer, &i);
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	printf("ret : %d\n", ft_printf("hello 15 non\n"));
	printf("trueret : %d\n", printf("hello 15 non\n"));
}
