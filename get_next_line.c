/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:14 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/29 12:18:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;
	char		*buff;
	size_t		i;

	if (fd == -1)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 2) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	tmp = (char *)malloc(sizeof(char));
	while (read(fd, buff, BUFFER_SIZE))
	{
		printf("buff : %s", buff);
		tmp = ft_strjoin(tmp, buff);
		printf("tmp : %s", tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	printf("tmp finale : %sfin tmp\n", tmp);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = ft_substr(tmp, 0, i);
	tmp = ft_substr(tmp, ft_strlen(line) + 1, ft_strlen(tmp) - ft_strlen(line));
	printf("tmp after sub:%s:\n", tmp);
	free(buff);
	free(tmp);
	return (line);
}

int	main(void)
{
	char	*str;
	int		i;
	int		fd;

	fd = open("file", O_RDONLY);
	i = 0;
	while (i < 4)
	{
		str = get_next_line(fd);
		// printf("\n:%s\n", str);
		i++;
	}
	return (0);
}
