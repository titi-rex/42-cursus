/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/10 16:27:55 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_countstr(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_findsize(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	return (size);
}

char	**ft_split_path(char const *s, char c)
{
	size_t	n_str;
	size_t	i;
	char	**split;

	n_str = ft_countstr(s, c);
	split = (char **)malloc((n_str + 1) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	i = 0;
	while (*s && i < n_str)
	{
		while (*s == c)
			s++;
		split[i] = ft_substr(s, 0, ft_findsize(s, c) + 1);
		if (!split[i])
		{
			ft_freesplit(split);
			return (NULL);
		}
		split[i][ft_findsize(s, c)] = '/';
		i++;
		s += ft_findsize(s, c);
	}
	split[i] = NULL;
	return (split);
}
