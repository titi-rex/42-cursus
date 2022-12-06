/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:09 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/06 11:53:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char));
		if (sub)
			sub[0] = 0;
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (sub);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i) != (char)c && *(s + i) != 0)
		i++;
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_self_append(char *self, char const *to_append)
{
	size_t	len_s;
	size_t	len_ta;
	char	*new_str;

	if (!self && !to_append)
		return (NULL);
	if (!self)
		len_s = 0;
	else
		len_s = ft_strlen(self);
	if (!to_append)
		len_ta = 0;
	else
		len_ta = ft_strlen(to_append);
	new_str = (char *)malloc((len_s + len_ta + 1) * sizeof(char));
	if (new_str)
	{
		if (self)
			ft_strlcpy(new_str, self, len_s + 1);
		if (to_append)
			ft_strlcpy(new_str + len_s, to_append, len_ta + 1);
	}
	if (self)
		free(self);
	return (new_str);
}
