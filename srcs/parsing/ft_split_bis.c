/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:03 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/22 21:23:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_is_charsetd(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	ft_wordlend(char *str, char *charset)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	while (str[i])
	{
		if (c == '\0' && (str[i] == '\'' || str[i] == '"'))
			c = str[i];
		else if (c == str[i])
			c = '\0';
		if (c == '\0' && ft_is_charsetd(str[i], charset))
			return (i);
		i++;
	}
	return (i);
}

static int	ft_wordcountd(char *str, char *charset)
{
	int		a;
	char	c;

	a = 0;
	c = '\0';
	while (*str)
	{
		if (c == '\0' && (*str == '\'' || *str == '\"'))
			c = *str;
		else if (c == *str)
			c = '\0';
		if ((ft_is_charsetd(*str, charset) && c == '\0' && *(str + 1) != 0))
		{
			a++;
			while (*str && ft_is_charsetd(*str, charset))
				str++;
			if (!*str)
				return (a);
		}
		else
			str++;
		if (!*str)
			a++;
	}
	return (a);
}

static char	*ft_strduppd(char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((j + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split_bis(char const *s, char c)
{
	char		**dest;
	int			size;
	int			j;
	int			i;
	char		charset[2];

	i = -1;
	charset[0] = c;
	charset[1] = '\0';
	while (*s && ft_is_charsetd(*s, charset))
		s++;
	size = ft_wordcountd((char *)s, charset);
	dest = malloc((size + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (++i < size)
	{
		while (ft_is_charsetd((char)*s, charset))
			s++;
		j = ft_wordlend((char *)s, charset);
		dest[i] = ft_strduppd((char *)s, j);
		s += j;
	}
	dest[size] = NULL;
	return (dest);
}
