/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:14 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/01 14:29:48 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_extract(int fd, char *s)
{
	int			len;
	char		buff[BUFFER_SIZE + 1];

	len = 1;
	while (!ft_strchr(s, '\n') && len)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		buff[len] = 0;
		s = ft_strjoin(s, buff);
	}
	return (s);
}

char	*ft_getline(char *s)
{
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (i == '\n')
		i++;
	return (ft_substr(s, 0, i));
}

char	*ft_keep(char *s)
{
	char	*keep;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	keep = ft_substr(s, i + 1, ft_strlen(s) - i);
	free(s);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s = ft_extract(fd, s);
	if (!s)
		return (NULL);
	line = ft_getline(s);
	if (*s)
		s = ft_keep(s);
	return (line);
}
